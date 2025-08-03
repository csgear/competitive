// https://www.luogu.com.cn/problem/P3796

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXP = 200;

struct TreeNode {
    int child[26];
    int fail;
    int end;
} tree[MAXN];

struct Pattern {
    int count;  // 出现次数
    int id;     // 模式串编号

    bool operator<(const Pattern& other) const {
        if (count != other.count) return count > other.count;
        return id < other.id;
    }
} patterns[MAXP];

string words[200];
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

void query(const string& text) {
    int cur = 0;
    for (char c : text) {
        int idx = c - 'a';
        cur = tree[cur].child[idx];

        // 统计所有匹配的模式串
        for (int temp = cur; temp != 0; temp = tree[temp].fail) {
            if (tree[temp].end > 0) {
                patterns[tree[temp].end].count++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        init();

        // 读入模式串并构建trie
        for (int i = 1; i <= n; i++) {
            cin >> words[i];
            patterns[i] = {0, i};
            build(words[i], i);
        }

        // 构建fail指针
        buildFail();

        // 读入文本串并查询
        string text;
        cin >> text;
        query(text);

        // 排序并输出结果
        sort(patterns + 1, patterns + n + 1);

        int maxCount = patterns[1].count;
        cout << maxCount << "\n";

        for (int i = 1; i <= n; i++) {
            if (patterns[i].count == maxCount) {
                cout << words[patterns[i].id] << "\n";
            } else {
                break;
            }
        }
    }

    return 0;
}
