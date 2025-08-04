// AC自动机 (Aho-Corasick Automaton) 模板
// 功能：多模式串匹配，在文本中同时查找多个模式串
// 时间复杂度：构建 O(∑|pattern|)，匹配 O(|text|)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct TreeNode {
    int child[26];
    int fail;
    int end;
} tree[MAXN];

int cnt;

void init() {
    cnt = 0;
    memset(tree, 0, sizeof(tree));
}

void build(const string& word, int id) {
    int cur = 0;
    for (char c : word) {
        int idx = c - 'a';
        if (tree[cur].child[idx] == 0) {
            tree[cur].child[idx] = ++cnt;
        }
        cur = tree[cur].child[idx];
    }
    tree[cur].end = id;
}

void buildFail() {
    queue<int> q;

    // 初始化第一层
    for (int i = 0; i < 26; i++) {
        if (tree[0].child[i] != 0) {
            tree[tree[0].child[i]].fail = 0;
            q.push(tree[0].child[i]);
        }
    }

    // BFS构建fail指针
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (tree[u].child[i] != 0) {
                int v = tree[u].child[i];
                tree[v].fail = tree[tree[u].fail].child[i];
                q.push(v);
            } else {
                tree[u].child[i] = tree[tree[u].fail].child[i];
            }
        }
    }
}

// 查询模式串在文本中的出现
// 返回匹配的模式串编号列表
vector<int> query(const string& text) {
    vector<int> matches;
    int cur = 0;

    for (char c : text) {
        int idx = c - 'a';
        cur = tree[cur].child[idx];

        for (int temp = cur; temp != 0; temp = tree[temp].fail) {
            if (tree[temp].end > 0) {
                matches.push_back(tree[temp].end);
            }
        }
    }

    return matches;
}

// 使用示例

// P3796 应用示例 - 统计出现次数最多的模式串
/*
struct Pattern {
    int count;
    int id;
    bool operator<(const Pattern& other) const {
        if (count != other.count) return count > other.count;
        return id < other.id;
    }
};

int main() {
    int n;
    vector<string> words(n+1);
    vector<Pattern> patterns(n+1);

    init();
    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        patterns[i] = {0, i};
        build(words[i], i);
    }
    buildFail();

    string text;
    cin >> text;
    vector<int> matches = query(text);
    for (int id : matches) {
        patterns[id].count++;
    }

    sort(patterns.begin() + 1, patterns.end());
    // 输出结果...
}
*/