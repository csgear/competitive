// https://cses.fi/problemset/task/1696
// Maximum Bipartite Matching using Max Flow (Ford-Fulkerson with DFS)

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev;
    int cap;
};

class MaxFlow {
   private:
    vector<vector<Edge>> graph;
    vector<bool> visited;

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        visited[v] = true;

        for (auto& edge : graph[v]) {
            if (!visited[edge.to] && edge.cap > 0) {
                int flow = dfs(edge.to, t, min(f, edge.cap));
                if (flow > 0) {
                    edge.cap -= flow;
                    graph[edge.to][edge.rev].cap += flow;
                    return flow;
                }
            }
        }
        return 0;
    }

   public:
    MaxFlow(int n) : graph(n), visited(n) {}

    void addEdge(int from, int to, int cap) {
        graph[from].push_back({to, (int)graph[to].size(), cap});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0});
    }

    int maxFlow(int source, int sink) {
        int flow = 0;
        while (true) {
            fill(visited.begin(), visited.end(), false);
            int f = dfs(source, sink, INT_MAX);
            if (f == 0) break;
            flow += f;
        }
        return flow;
    }

    // Get the actual matching pairs
    vector<pair<int, int>> getMatching(int n, int m) {
        vector<pair<int, int>> matching;

        // Check edges from boys (1 to n) to girls (n+1 to n+m)
        for (int boy = 1; boy <= n; boy++) {
            for (auto& edge : graph[boy]) {
                int girl_node = edge.to;
                // If this is an edge to a girl and it's saturated (cap = 0)
                if (girl_node > n && girl_node <= n + m && edge.cap == 0) {
                    int girl = girl_node - n;  // Convert back to original girl numbering
                    matching.push_back({boy, girl});
                    break;  // Each boy can match with at most one girl
                }
            }
        }

        return matching;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // Create flow network:
    // Node 0: source
    // Nodes 1 to n: boys
    // Nodes n+1 to n+m: girls
    // Node n+m+1: sink

    MaxFlow mf(n + m + 2);

    // Add edges from source to all boys (capacity 1)
    for (int i = 1; i <= n; i++) {
        mf.addEdge(0, i, 1);
    }

    // Add edges from all girls to sink (capacity 1)
    for (int i = 1; i <= m; i++) {
        mf.addEdge(n + i, n + m + 1, 1);
    }

    // Add edges between boys and girls based on input
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        // Boy a (node a) to Girl b (node n+b) with capacity 1
        mf.addEdge(a, n + b, 1);
    }

    // Find maximum flow from source (0) to sink (n+m+1)
    int maxMatching = mf.maxFlow(0, n + m + 1);

    // Get the actual matching pairs
    vector<pair<int, int>> matching = mf.getMatching(n, m);

    cout << maxMatching << '\n';
    for (auto& pair : matching) {
        cout << pair.first << " " << pair.second << '\n';
    }

    return 0;
}
