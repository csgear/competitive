#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<vector<int>> graph;
vector<int> memo;
int id_count = 0;

int get_id(const string& s) {
    if (mp.find(s) == mp.end()) {
        mp[s] = id_count++;
        graph.push_back({});
    }
    return mp[s];
}

int dfs(int u, int end) {
    if (u == end) return 1;
    if (memo[u] != -1) return memo[u];
    int total = 0;
    for (int v : graph[u]) {
        total += dfs(v, end);
    }
    memo[u] = total;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    int start = -1, end = -1;

    while (getline(cin, line)) {
        stringstream ss(line);
        string node;
        getline(ss, node, ':');
        int u = get_id(node);

        if (node == "you" && start == -1) start = u;

        string neighbor;
        while (ss >> neighbor) {
            int v = get_id(neighbor);
            if (neighbor == "out" && end == -1) end = v;
            graph[u].push_back(v);
        }
    }

    memo.assign(graph.size(), -1);

    cout << dfs(start, end) << "\n";

    return 0;
}