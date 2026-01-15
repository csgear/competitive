// https://atcoder.jp/contests/abc437/tasks/abc437_e
// E - Sort Arrays

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

struct TrieNode {
    map<int, int> children;
    vector<int> indices;
};

vector<TrieNode> trie(MAXN);
vector<int> result;

void dfs(int u) {
    for (int idx : trie[u].indices) {
        result.push_back(idx);
    }

    for (const auto& pair : trie[u].children) {
        int child_node = pair.second;
        dfs(child_node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(n + 1, -1);
    pos[0] = 0;
    int next_node_id = 1;

    for (int i = 1; i <= n; i++) {
        int p, y;
        cin >> p >> y;

        if (trie[pos[p]].children.find(y) == trie[pos[p]].children.end()) {
            trie[pos[p]].children[y] = next_node_id++;
        }

        pos[i] = trie[pos[p]].children[y];
        trie[pos[i]].indices.push_back(i);
    }

    dfs(0);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << " ";
    }
    cout << endl;

    return 0;
}
