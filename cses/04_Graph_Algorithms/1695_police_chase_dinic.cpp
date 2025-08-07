// https://cses.fi/problemset/task/1695
// Police Chase - Minimum Cut Problem using Max Flow

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 2005;
const int INF = 1e9;

/*
 * FLOW NETWORK REPRESENTATION:
 * - Each edge has capacity (max flow it can handle) and current flow
 * - For undirected edges in original graph, we create bidirectional edges
 * - Reverse edges are used for flow cancellation in case we need to backtrack
 */
struct Edge {
    int to, next, cap, flow;
} edges[MAXM];

int head[MAXN], cnt = 0;
int level[MAXN], cur[MAXN];  // level = distance from source, cur = current edge optimization

/*
 * ADD EDGE FUNCTION:
 * For each undirected edge u-v in original graph:
 * - Add directed edge u->v with capacity 'cap'
 * - Add directed edge v->u with capacity 'cap'
 * - These form a pair: edges[i] and edges[i^1] are reverse of each other
 */
void add_edge(int u, int v, int cap) {
    edges[cnt] = {v, head[u], cap, 0};
    head[u] = cnt++;
    edges[cnt] = {u, head[v], cap, 0};
    head[v] = cnt++;
}

/*
 * DINIC'S ALGORITHM - PHASE 1: BUILD LEVEL GRAPH
 * - Use BFS to assign levels (shortest distances) from source
 * - Only consider edges with remaining capacity (cap > flow)
 * - Level graph helps ensure we only use shortest augmenting paths
 */
bool bfs(int s, int t, int n) {
    fill(level, level + n + 1, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (level[v] < 0 && edges[i].flow < edges[i].cap) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] >= 0;  // Return true if sink is reachable
}

/*
 * DINIC'S ALGORITHM - PHASE 2: FIND BLOCKING FLOWS
 * - Use DFS to find augmenting paths in level graph
 * - Only move to next level (level[v] = level[u] + 1)
 * - Current edge optimization: don't re-examine used edges
 * - Push flow through path and update reverse edges
 */
int dfs(int u, int t, int pushed) {
    if (u == t || pushed == 0) return pushed;

    for (int& i = cur[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;

        if (level[v] != level[u] + 1 || edges[i].cap <= edges[i].flow) continue;

        int tr = dfs(v, t, min(pushed, edges[i].cap - edges[i].flow));
        if (tr > 0) {
            edges[i].flow += tr;      // Add flow to forward edge
            edges[i ^ 1].flow -= tr;  // Subtract flow from reverse edge
            return tr;
        }
    }
    return 0;
}

/*
 * MAX FLOW MAIN ALGORITHM (DINIC'S):
 * 1. Build level graph using BFS
 * 2. If sink unreachable, terminate
 * 3. Reset current edge pointers
 * 4. Find blocking flows using DFS
 * 5. Repeat until no more augmenting paths
 *
 * TIME COMPLEXITY: O(V^2 * E)
 */
int max_flow(int s, int t, int n) {
    int flow = 0;
    while (bfs(s, t, n)) {                              // Phase 1: Build level graph
        for (int i = 1; i <= n; i++) cur[i] = head[i];  // Reset current edge pointers
        while (int pushed = dfs(s, t, INF)) {           // Phase 2: Find blocking flows
            flow += pushed;
        }
    }
    return flow;
}

/*
 * MIN-CUT IDENTIFICATION:
 * After max flow terminates, the residual graph shows the min-cut:
 * 1. Do BFS from source in residual graph (edges with remaining capacity)
 * 2. Nodes reachable = S, nodes unreachable = T
 * 3. Min-cut edges = edges from S to T that are fully saturated
 *
 * MAX-FLOW MIN-CUT THEOREM: max flow value = min cut capacity
 */
void find_min_cut(int s, int n, vector<pair<int, int>>& cut_edges) {
    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(s);
    reachable[s] = true;

    // BFS in residual graph to find reachable nodes
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (!reachable[v] && edges[i].flow < edges[i].cap) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    // Find cut edges: from reachable to unreachable with full capacity used
    set<pair<int, int>> cut_set;  // Use set to avoid duplicates
    for (int u = 1; u <= n; u++) {
        if (reachable[u]) {
            for (int i = head[u]; i != -1; i = edges[i].next) {
                int v = edges[i].to;
                // Check if this edge crosses the cut and is saturated
                if (!reachable[v] && edges[i].cap > 0 && edges[i].flow >= edges[i].cap) {
                    // Always store edge as (min, max) to avoid duplicates
                    cut_set.insert({min(u, v), max(u, v)});
                }
            }
        }
    }

    // Convert set to vector
    for (auto& edge : cut_set) {
        cut_edges.push_back(edge);
    }
}

/*
 * MAIN SOLUTION:
 *
 * PROBLEM: Find minimum number of edges to remove to disconnect node 1 from node n
 * APPROACH: This is a classic minimum cut problem
 *
 * KEY INSIGHTS:
 * 1. Model as flow network: each edge has capacity 1 (can be "cut" once)
 * 2. Max-Flow Min-Cut Theorem: maximum flow = minimum cut capacity
 * 3. After max flow, residual graph reveals which edges to cut
 *
 * ALGORITHM STEPS:
 * 1. Build flow network with edge capacities = 1
 * 2. Run max flow from source (1) to sink (n)
 * 3. The max flow value = minimum cut size
 * 4. Find cut edges using residual graph reachability
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    fill(head, head + n + 1, -1);  // Initialize adjacency list heads

    // Build flow network: each undirected edge becomes bidirectional with capacity 1
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v, 1);  // This creates both u->v and v->u with capacity 1
    }

    // Find maximum flow from 1 to n
    int min_cut = max_flow(1, n, n);
    cout << min_cut << "\n";

    // Find and output the actual cut edges
    vector<pair<int, int>> cut_edges;
    find_min_cut(1, n, cut_edges);

    for (auto& edge : cut_edges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}

/*
 * STUDY NOTES FOR UNDERSTANDING:
 *
 * 1. FLOW NETWORKS:
 *    - Directed graph with source, sink, and edge capacities
 *    - Flow = amount of "stuff" flowing through edges
 *    - Capacity constraint: flow ≤ capacity for each edge
 *    - Conservation: flow in = flow out for non-source/sink nodes
 *
 * 2. MAX FLOW PROBLEM:
 *    - Find maximum amount of flow from source to sink
 *    - Classic algorithms: Ford-Fulkerson, Edmonds-Karp, Dinic's
 *
 * 3. MIN CUT PROBLEM:
 *    - Find minimum capacity edges to remove to disconnect source from sink
 *    - Cut = partition of vertices into two sets (S containing source, T containing sink)
 *    - Cut capacity = sum of capacities of edges from S to T
 *
 * 4. MAX-FLOW MIN-CUT THEOREM:
 *    - Value of maximum flow = capacity of minimum cut
 *    - Fundamental result connecting these two problems
 *
 * 5. DINIC'S ALGORITHM:
 *    - Level graphs ensure shortest augmenting paths
 *    - Current edge optimization avoids re-scanning used edges
 *    - Time complexity: O(V²E), often much faster in practice
 *
 * 6. APPLICATIONS:
 *    - Network reliability, transportation, assignment problems
 *    - Bipartite matching, edge connectivity, vertex connectivity
 *    - Image segmentation, project selection
 */