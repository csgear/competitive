// https://cses.fi/problemset/task/1686

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<vector<int>> graph(MAXN), reverse_graph(MAXN);
bool visited[MAXN];
int component[MAXN];
long long scc_coins[MAXN];
int scc_count = 0;
vector<int> finish_order;
vector<unordered_set<int>> scc_edges(MAXN);

void dfs1(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto i : graph[s]) dfs1(i);
    finish_order.push_back(s);
}

void dfs2(int s) {
    if (visited[s]) return;
    component[s] = scc_count;
    visited[s] = true;
    for (auto i : reverse_graph[s]) dfs2(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    reverse_graph.resize(n + 1);
    scc_edges.resize(MAXN);

    vector<long long> coins(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    // Step 1: Find SCCs using Kosaraju's algorithm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, 0, sizeof visited);
    for (int i = finish_order.size() - 1; i >= 0; i--) {
        int u = finish_order[i];
        if (!visited[u]) {
            scc_count++;
            dfs2(u);
        }
    }

    // Step 2: Sum coins in each SCC and build compressed graph
    for (int i = 1; i <= n; i++) {
        scc_coins[component[i]] += coins[i];
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : graph[i]) {
            if (component[i] != component[j]) {
                scc_edges[component[i]].insert(component[j]);
            }
        }
    }

    // Step 3: DP on compressed DAG in reverse topological order
    vector<int> topo_order;
    memset(visited, 0, sizeof visited);

    while (!finish_order.empty()) {
        int i = finish_order.back();
        finish_order.pop_back();
        if (!visited[component[i]]) {
            topo_order.push_back(component[i]);
            visited[component[i]] = true;
        }
    }

    // Process SCCs in reverse topological order
    while (!topo_order.empty()) {
        int u = topo_order.back();
        topo_order.pop_back();

        long long max_path = scc_coins[u];
        for (auto next_scc : scc_edges[u]) {
            max_path = max(max_path, scc_coins[u] + scc_coins[next_scc]);
        }
        scc_coins[u] = max_path;
    }

    // Answer: maximum among all SCCs
    long long answer = *max_element(scc_coins + 1, scc_coins + scc_count + 1);
    cout << answer << "\n";

    return 0;
}