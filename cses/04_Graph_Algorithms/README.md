# CSES 04 Graph Algorithms

This section contains solutions for graph algorithm problems from CSES Problem Set. The problems cover fundamental graph algorithms including traversal, shortest paths, co### Advanced Techniques

- **Bipartite Matching**: Hungarian algorithm, max flow reduction
- **Negative Cycles**: Bellman-Ford with cycle reconstruction
- **Maximum Flow**: Dinic's algorithm for efficient flow computation
- **Edge-Disjoint Paths**: Path reconstruction from residual graphstivity, and advanced techniques.

## Problems Overview

### Basic Graph Traversal

| Problem                                          | Algorithm        | Complexity | Key Concepts                         |
| ------------------------------------------------ | ---------------- | ---------- | ------------------------------------ |
| [1192 - Counting Rooms](1192_counting_rooms.cpp) | DFS/BFS          | O(nm)      | Connected components, grid traversal |
| [1193 - Labyrinth](1193_labyrinth.cpp)           | BFS              | O(nm)      | Shortest path, path reconstruction   |
| [1194 - Monsters](1194_monsters.cpp)             | Multi-source BFS | O(nm)      | Multi-source shortest path           |

### Functional Graphs

| Problem                                                 | Algorithm                        | Complexity | Key Concepts                        |
| ------------------------------------------------------- | -------------------------------- | ---------- | ----------------------------------- |
| [1750 - Planets Queries I](1750_planets_queries_1.cpp)  | Binary Lifting                   | O(log k)   | k-step reachability queries         |
| [1160 - Planets Queries II](1160_planets_queries_2.cpp) | Cycle Detection + Binary Lifting | O(log n)   | Distance queries with cycles        |
| [1751 - Planets Cycles](1751_planets_cycles.cpp)        | DFS                              | O(n)       | Finding cycles in functional graphs |

### Shortest Paths

| Problem                                                      | Algorithm         | Complexity  | Key Concepts                  |
| ------------------------------------------------------------ | ----------------- | ----------- | ----------------------------- |
| [1667 - Message Route](1667_message_route.cpp)               | BFS               | O(V+E)      | Unweighted shortest path      |
| [1671 - Shortest Routes I](1671_shortest_routes_1.cpp)       | Dijkstra          | O(E log V)  | Single-source shortest path   |
| [1672 - Shortest Routes II](1672_shortest_routers_2.cpp)     | Floyd-Warshall    | O(V³)       | All-pairs shortest path       |
| [1673 - High Score](1673_high_score.cpp)                     | Bellman-Ford      | O(VE)       | Longest path, negative cycles |
| [1195 - Flight Discount](1195_flight_discount.cpp)           | Modified Dijkstra | O(E log V)  | State-space search            |
| [1196 - Flight Routes](1196_flight_routes.cpp)               | K-shortest paths  | O(kE log V) | Multiple optimal solutions    |
| [1197 - Cycle Finding](1197_cycle_finding.cpp)               | Bellman-Ford      | O(VE)       | Negative cycle detection      |
| [1202 - Investigation](1202_investigation.cpp)               | Dijkstra + DP     | O(E log V)  | Counting shortest paths       |
| [1680 - Longest Flight Route](1680_longest_flight_route.cpp) | Topological DP    | O(V+E)      | Longest path in DAG           |

### Connectivity & Components

| Problem                                                      | Algorithm       | Complexity | Key Concepts               |
| ------------------------------------------------------------ | --------------- | ---------- | -------------------------- |
| [1666 - Building Roads](1666_building_roads.cpp)             | DFS             | O(V+E)     | Connected components       |
| [1668 - Building Teams](1668_building_teams.cpp)             | DFS/BFS         | O(V+E)     | Bipartite graph checking   |
| [1669 - Round Trip](1669_round_trip.cpp)                     | DFS             | O(V+E)     | Cycle detection            |
| [1678 - Round Trip II](1678_round_trip_2.cpp)                | DFS             | O(V+E)     | Cycle detection (directed) |
| [1676 - Road Construction](1676_road_construction.cpp)       | Union-Find      | O(α(V))    | Dynamic connectivity       |
| [1682 - Flight Routes Check](1682_flight_routes_check.cpp)   | Kosaraju/Tarjan | O(V+E)     | Strong connectivity        |
| [1683 - Planets and Kingdoms](1683_planets_and_kingdoms.cpp) | Kosaraju        | O(V+E)     | SCC decomposition          |

### Advanced Graph Problems

| Problem                                                  | Algorithm          | Complexity | Key Concepts                  |
| -------------------------------------------------------- | ------------------ | ---------- | ----------------------------- |
| [1679 - Course Schedule](1679_course_schedule.cpp)       | Topological Sort   | O(V+E)     | DAG ordering                  |
| [1681 - Game Routes](1681_game_routes.cpp)               | DP on DAG          | O(V+E)     | Counting paths                |
| [1675 - Road Reparation](1675_road_reparation.cpp)       | Kruskal's MST      | O(E log E) | Minimum spanning tree         |
| [1684 - Giant Pizza](1684_giant_pizza.cpp)               | 2-SAT              | O(V+E)     | Boolean satisfiability        |
| [1686 - Coin Collector](1686_coin_collector.cpp)         | SCC + DP           | O(V+E)     | SCC compression, longest path |
| [1689 - Knight's Tour](1689_knights_tour.cpp)            | Backtracking       | O(8^64)    | Warnsdorff's heuristic        |
| [1691 - Mail Delivery](1691_mail_delivery.cpp)           | Eulerian Circuit   | O(V+E)     | Eulerian tour, Hierholzer's   |
| [1692 - De Bruijn Sequence](1692_de_bruijn_sequence.cpp) | Eulerian Path      | O(k^n)     | De Bruijn graph construction  |
| [1694 - Download Speed](1694_download_speed_dinic.cpp)   | Dinic's Algorithm  | O(V²E)     | Maximum flow, blocking flows  |
| [1696 - School Dance](1696_school_dance.cpp)             | Hungarian/Max Flow | O(V³)      | Bipartite matching            |
| [1711 - Distinct Routes](1711_distinct_routes.cpp)       | Max Flow + Paths   | O(V²E)     | Edge-disjoint path finding    |

## Implementation Notes

### Graph Representation

All solutions use **adjacency lists** with custom `Edge` structures:

```cpp
struct Edge {
    int to, nxt;
    ll w;  // weight for weighted graphs
} edges[MAXM];
```

### Common Patterns

#### 1. DFS Template

```cpp
bool visited[MAXN];
void dfs(int u) {
    visited[u] = true;
    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;
        if (!visited[v]) dfs(v);
    }
}
```

#### 2. BFS Template

```cpp
queue<int> q;
bool visited[MAXN];
q.push(start);
visited[start] = true;
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;
        if (!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
    }
}
```

#### 3. Dijkstra Template

```cpp
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<ll> dist(n + 1, LLONG_MAX);
dist[start] = 0;
pq.push({0, start});

while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;  // Skip outdated entries

    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;
        ll w = edges[e].w;
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

#### 4. 3-Color DFS Cycle Detection (Directed Graphs)

```cpp
int color[MAXN];    // 0: white, 1: gray, 2: black
int parent[MAXN];
vector<int> cycle;

bool dfs(int u) {
    color[u] = 1;   // gray - currently processing

    for (int e = head[u]; e != 0; e = edges[e].nxt) {
        int v = edges[e].to;

        if (color[v] == 1) {  // back edge found - cycle detected
            // reconstruct cycle
            cycle.push_back(v);
            for (int cur = u; cur != v; cur = parent[cur]) {
                cycle.push_back(cur);
            }
            cycle.push_back(v);
            return true;
        }

        if (color[v] == 0) {  // white - unvisited
            parent[v] = u;
            if (dfs(v)) return true;
        }
        // black nodes (color[v] == 2) are already processed - skip
    }

    color[u] = 2;   // black - completely processed
    return false;
}

// Usage: iterate through all unvisited nodes
for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
        if (dfs(i)) {
            // cycle found in 'cycle' vector
            break;
        }
    }
}
```

## Algorithm Categories

### **Traversal & Basic Connectivity**

- Grid-based problems: DFS/BFS on 2D arrays
- Connected components: Union-Find or DFS
- Path finding: BFS for unweighted, Dijkstra for weighted

### **Shortest Paths**

- **Single-source**: Dijkstra (non-negative), Bellman-Ford (general)
- **All-pairs**: Floyd-Warshall for dense graphs
- **Specialized**: Modified state-space search for constraints

### **Strong Connectivity**

- **Kosaraju's Algorithm**: Two-pass DFS for SCC
- **Applications**: Checking strong connectivity, SCC decomposition

### **Advanced Techniques**

- **Bipartite Matching**: Hungarian algorithm, max flow reduction
- **Negative Cycles**: Bellman-Ford with cycle reconstruction
- **Topological Sorting**: DFS-based ordering for DAGs

## Key Insights

1. **State-space modeling**: Problems like flight discount require tracking additional state
2. **Path reconstruction**: Maintain parent pointers for path queries
3. **Multiple solutions**: K-shortest paths, multiple optimal solutions
4. **Cycle handling**: Different approaches for directed vs undirected graphs
5. **Optimization**: Choose algorithm based on graph density and constraints

- **Key Ideas**: Use BFS to find the shortest path and reconstruct the path using parent pointers.

## 1668 - Building Teams

- **Description**: Assign each node to one of two teams such that no two adjacent nodes are on the same team, or report impossibility.
- **Key Ideas**: Use DFS or BFS to check if the graph is bipartite, assigning alternating teams. If a conflict is found, output impossible.

## 1669 - Round Trip

- **Description**: Find any cycle in an undirected graph, or report if none exists.
- **Key Ideas**: Use DFS to detect cycles, keeping track of parent nodes to reconstruct the cycle path.

## 1671 - Shortest Routes I

- **Description**: Find the shortest path from node 1 to all other nodes in a weighted directed graph.
- **Key Ideas**: Use Dijkstra's algorithm with a priority queue for efficient shortest path computation.

## 1679 - Course Schedule

- **Description**: Find a valid course ordering respecting prerequisites, or report impossibility.
- **Key Ideas**: Topological sorting using either Kahn's algorithm (BFS with indegree) or DFS with 3-color scheme. Cycle detection indicates impossible scheduling.

## 1680 - Longest Flight Route

- **Description**: Find the longest path from city 1 to city n in a DAG, or report if no path exists.
- **Key Ideas**: Use topological sort with DP. Only process nodes reachable from source. Track parent pointers for path reconstruction.

## 1196 - Flight Routes

- **Description**: Find the k shortest paths from city 1 to city n.
- **Key Ideas**: Modified Dijkstra's allowing multiple visits per node (up to k times). Use priority queue and track k shortest distances per node.

## 1197 - Cycle Finding

- **Description**: Find a negative-weight cycle in a directed graph and output its vertices.
- **Key Ideas**: Use Bellman-Ford algorithm. After n-1 iterations, run one more to detect negative cycles. Trace back to find the actual cycle vertices.

## 1202 - Investigation

- **Description**: Count shortest paths, minimum flights, and maximum flights from city 1 to all other cities.
- **Key Ideas**: Modified Dijkstra with additional DP tracking. For each shortest path found, update path count, minimum edges, and maximum edges simultaneously.

## 1673 - High Score

- **Description**: Find the maximum score path from room 1 to room n, detecting if infinite score is possible.
- **Key Ideas**: Use Bellman-Ford with negated weights to find longest paths. Check for positive cycles reachable from source and can reach destination.

## 1678 - Round Trip II

- **Description**: Find any cycle in a directed graph, or report if none exists.
- **Key Ideas**: Use DFS with 3-color scheme (white/gray/black). When visiting a gray node, a back edge is found indicating a cycle. Reconstruct cycle using parent pointers.

## 1684 - Giant Pizza

- **Description**: 2-SAT problem: assign boolean values to variables satisfying all given constraints.
- **Key Ideas**: Build implication graph, find strongly connected components using Kosaraju's algorithm. If any variable and its negation are in the same SCC, output "IMPOSSIBLE". Otherwise, assign values based on topological ordering of SCCs.

## 1686 - Coin Collector

- **Description**: Find the maximum coins collectable by traversing the directed graph from any starting room.
- **Key Ideas**: Find strongly connected components, compress to DAG. Use topological sort with DP to find longest path in the compressed graph. Each SCC contributes sum of its coins.

## 1691 - Mail Delivery

- **Description**: Find an Eulerian circuit visiting each edge exactly once, or report impossibility.
- **Key Ideas**: Check if all vertices have even degree. Use Hierholzer's algorithm with forward star representation. Maintain current edge pointer for each vertex to avoid rescanning used edges.

## 1692 - De Bruijn Sequence

- **Description**: Construct a De Bruijn sequence B(k,n) containing every possible n-length string over k-alphabet exactly once as substring.
- **Key Ideas**: Build De Bruijn graph where vertices are (n-1)-length strings and edges are n-length strings. Find Eulerian path in this graph to construct the sequence.

## 1750 - Planets Queries I

- **Description**: Process queries asking: starting from planet x, where do we end up after exactly k steps?
- **Key Ideas**: Binary lifting preprocessing. Build jump tables for powers of 2. Answer each query in O(log k) time by decomposing k into binary representation.

## 1160 - Planets Queries II

- **Description**: Find minimum steps to reach planet b from planet a in a functional graph.
- **Key Ideas**: Combine cycle detection with binary lifting. Handle three cases: both in same cycle, one in cycle tail, different cycle components. Use LCA-style approach for complex cases.

## 1751 - Planets Cycles

- **Description**: For each planet, find minimum steps to reach any planet that is part of a cycle.
- **Key Ideas**: Simple DFS-based approach. For each unvisited node, follow the path until reaching a visited node. Mark cycle nodes and compute distances efficiently.

## 1675 - Road Reparation

- **Description**: Find the minimum cost to repair roads to connect all cities, or report if impossible.
- **Key Ideas**: Minimum Spanning Tree (MST) using Kruskal's algorithm with Union-Find. Sort edges by cost, add minimum cost edges that don't create cycles. Check if all cities are connected.

## 1676 - Road Construction

- **Description**: Process road construction queries, outputting the number of connected components and size of the largest component after each road.
- **Key Ideas**: Dynamic connectivity using Union-Find with union by size. Track component count and maximum component size. Each merge operation updates both metrics efficiently.

## 1682 - Flight Routes Check

- **Description**: Check if all cities are reachable from each other in a directed graph. If not, output a pair of cities that can't reach each other.
- **Key Ideas**: Strong connectivity check using Kosaraju's algorithm for strongly connected components (SCCs). If more than 1 SCC exists, find two cities in different SCCs.

## 1683 - Planets and Kingdoms

- **Description**: Find all strongly connected components in a directed graph and assign component IDs to each node.
- **Key Ideas**: Kosaraju's algorithm for SCC decomposition. Two-pass DFS: first on original graph for finishing times, second on reversed graph in reverse order to identify components. Assign unique IDs to each SCC.

## Algorithm Categories Summary

### **Graph Traversal & Basic Connectivity**

- **1192 - Counting Rooms**: DFS/BFS on grid
- **1193 - Labyrinth**: BFS pathfinding
- **1194 - Monsters**: Multi-source BFS
- **1667 - Message Route**: BFS shortest path (unweighted)

### **Functional Graphs**

- **1750 - Planets Queries I**: Binary lifting for k-step queries
- **1160 - Planets Queries II**: Distance queries with cycle handling
- **1751 - Planets Cycles**: Cycle detection and distance computation

### **Cycle Detection & Properties**

- **1669 - Round Trip**: Cycle detection in undirected graphs
- **1678 - Round Trip II**: Cycle detection in directed graphs (DFS 3-color)
- **1197 - Cycle Finding**: Negative cycle detection with Bellman-Ford

### **Shortest Paths & Variants**

- **1671 - Shortest Routes I**: Dijkstra's algorithm
- **1672 - Shortest Routes II**: Floyd-Warshall all-pairs
- **1673 - High Score**: Longest path with positive cycle detection
- **1195 - Flight Discount**: State-space Dijkstra
- **1196 - Flight Routes**: k-shortest paths variant
- **1202 - Investigation**: Dijkstra with path counting
- **1680 - Longest Flight Route**: Longest path in DAG with topological sort

### **Union-Find & Dynamic Connectivity**

- **1675 - Road Reparation**: Kruskal's MST with Union-Find
- **1676 - Road Construction**: Dynamic connectivity tracking
- **1666 - Building Roads**: Connected components with Union-Find

### **Strongly Connected Components (SCC)**

- **1682 - Flight Routes Check**: SCC existence check with Kosaraju's
- **1683 - Planets and Kingdoms**: Complete SCC decomposition
- **1684 - Giant Pizza**: 2-SAT using SCC
- **1686 - Coin Collector**: SCC compression + longest path DP

### **Graph Properties & Validation**

- **1668 - Building Teams**: Bipartite graph checking
- **1679 - Course Schedule**: Topological sorting & cycle detection

### **Advanced Graph Algorithms**

- **1681 - Game Routes**: DP on DAG for path counting
- **1689 - Knight's Tour**: Backtracking with Warnsdorff's heuristic
- **1691 - Mail Delivery**: Eulerian circuit with Hierholzer's algorithm
- **1692 - De Bruijn Sequence**: Eulerian path in De Bruijn graphs
- **1696 - School Dance**: Bipartite matching with max flow

### **Maximum Flow & Network Flows**

- **1694 - Download Speed**: Dinic's algorithm for maximum flow
- **1711 - Distinct Routes**: Edge-disjoint path reconstruction from max flow

## Additional Implementation Details

### 1689 - Knight's Tour

- **Description**: Find a sequence of knight moves visiting each square of a chessboard exactly once.
- **Algorithm**: Backtracking with Warnsdorff's heuristic
- **Key Ideas**:
  - Use Warnsdorff's rule: always move to square with fewest onward moves
  - This heuristic dramatically reduces search space and avoids dead ends
  - Backtrack when no valid moves available

```cpp
// Warnsdorff's heuristic: count accessibility
int countMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny)) count++;
    }
    return count;
}
```

### 1694 - Download Speed

- **Description**: Find maximum flow from source to sink in a flow network.
- **Algorithm**: Dinic's algorithm with blocking flows
- **Key Ideas**:
  - Build level graph using BFS
  - Find blocking flow using DFS
  - O(V²E) complexity, efficient for competitive programming
  - Use forward-star graph representation with XOR trick for reverse edges

```cpp
// Dinic's algorithm structure
int dinic() {
    int max_flow = 0;
    while (bfs()) {  // Build level graph
        memcpy(cur, head, sizeof(head));
        max_flow += dfs(1, INT_MAX);  // Find blocking flow
    }
    return max_flow;
}
```

### 1711 - Distinct Routes

- **Description**: Find k edge-disjoint paths from source to sink and output all paths.
- **Algorithm**: Maximum flow + path reconstruction
- **Key Ideas**:
  - First run max flow to determine number of paths
  - Track edge IDs to distinguish original from reverse edges
  - Reconstruct paths by following edges with flow (capacity = 0)
  - Mark used edges to ensure edge-disjoint property

```cpp
// Path reconstruction from residual graph
vector<int> find_path() {
    vector<int> path = {1};
    int x = 1;
    while (x != n) {
        for (int i = head[x]; i; i = e[i].nxt) {
            // Look for used edges: cap=0, valid ID, not visited
            if (e[i].cap == 0 && e[i].id > 0 && !vis[e[i].id]) {
                path.push_back(e[i].v);
                vis[e[i].id] = true;
                x = e[i].v;
                break;
            }
        }
    }
    return path;
}
```
