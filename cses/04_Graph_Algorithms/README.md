# CSES 04 Graph Algorithms

This section contains solutions for graph algorithm problems from CSES Problem Set. The problems cover fundamental graph algorithms including traversal, shortest paths, connectivity, and advanced techniques.

## Problems Overview

### Basic Graph Traversal

| Problem                                          | Algorithm        | Complexity | Key Concepts                         |
| ------------------------------------------------ | ---------------- | ---------- | ------------------------------------ |
| [1192 - Counting Rooms](1192_counting_rooms.cpp) | DFS/BFS          | O(nm)      | Connected components, grid traversal |
| [1193 - Labyrinth](1193_labyrinth.cpp)           | BFS              | O(nm)      | Shortest path, path reconstruction   |
| [1194 - Monsters](1194_monsters.cpp)             | Multi-source BFS | O(nm)      | Multi-source shortest path           |

### Shortest Paths

| Problem                                                      | Algorithm         | Complexity  | Key Concepts                |
| ------------------------------------------------------------ | ----------------- | ----------- | --------------------------- |
| [1667 - Message Route](1667_message_route.cpp)               | BFS               | O(V+E)      | Unweighted shortest path    |
| [1671 - Shortest Routes I](1671_shortest_routes_1.cpp)       | Dijkstra          | O(E log V)  | Single-source shortest path |
| [1672 - Shortest Routes II](1672_shortest_routers_2.cpp)     | Floyd-Warshall    | O(V³)       | All-pairs shortest path     |
| [1195 - Flight Discount](1195_flight_discount.cpp)           | Modified Dijkstra | O(E log V)  | State-space search          |
| [1196 - Flight Routes](1196_flight_routes.cpp)               | K-shortest paths  | O(kE log V) | Multiple optimal solutions  |
| [1680 - Longest Flight Route](1680_longest_flight_route.cpp) | Topological DP    | O(V+E)      | Longest path in DAG         |

### Connectivity & Components

| Problem                                                      | Algorithm       | Complexity | Key Concepts             |
| ------------------------------------------------------------ | --------------- | ---------- | ------------------------ |
| [1666 - Building Roads](1666_building_roads.cpp)             | DFS             | O(V+E)     | Connected components     |
| [1668 - Building Teams](1668_building_teams.cpp)             | DFS/BFS         | O(V+E)     | Bipartite graph checking |
| [1669 - Round Trip](1669_round_trip.cpp)                     | DFS             | O(V+E)     | Cycle detection          |
| [1676 - Road Construction](1676_road_construction.cpp)       | Union-Find      | O(α(V))    | Dynamic connectivity     |
| [1682 - Flight Routes Check](1682_flight_routes_check.cpp)   | Kosaraju/Tarjan | O(V+E)     | Strong connectivity      |
| [1683 - Planets and Kingdoms](1683_planets_and_kingdoms.cpp) | Kosaraju        | O(V+E)     | SCC decomposition        |

### Advanced Graph Problems

| Problem                                            | Algorithm          | Complexity | Key Concepts             |
| -------------------------------------------------- | ------------------ | ---------- | ------------------------ |
| [1197 - Cycle Finding](1197_cycle_finding.cpp)     | Bellman-Ford       | O(VE)      | Negative cycle detection |
| [1675 - Road Reparation](1675_road_reparation.cpp) | Kruskal's MST      | O(E log E) | Minimum spanning tree    |
| [1679 - Course Schedule](1679_course_schedule.cpp) | Topological Sort   | O(V+E)     | DAG ordering             |
| [1681 - Game Routes](1681_game_routes.cpp)         | DP on DAG          | O(V+E)     | Counting paths           |
| [1696 - School Dance](1696_school_dance.cpp)       | Hungarian/Max Flow | O(V³)      | Bipartite matching       |

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

---

## Algorithm Categories Summary

### **Graph Traversal & Basic Connectivity**

- **1192 - Counting Rooms**: DFS/BFS on grid
- **1193 - Labyrinth**: BFS pathfinding
- **1194 - Monsters**: Multi-source BFS
- **1667 - Message Route**: BFS shortest path (unweighted)

### **Union-Find & Dynamic Connectivity**

- **1675 - Road Reparation**: Kruskal's MST with Union-Find
- **1676 - Road Construction**: Dynamic connectivity tracking
- **1666 - Building Roads**: Connected components with Union-Find

### **Strongly Connected Components (SCC)**

- **1682 - Flight Routes Check**: SCC existence check with Kosaraju's
- **1683 - Planets and Kingdoms**: Complete SCC decomposition

### **Graph Properties & Validation**

- **1668 - Building Teams**: Bipartite graph checking
- **1669 - Round Trip**: Cycle detection in undirected graphs
- **1679 - Course Schedule**: Topological sorting & cycle detection

### **Shortest Paths**

- **1671 - Shortest Routes I**: Dijkstra's algorithm
- **1196 - Flight Routes**: k-shortest paths variant
- **1680 - Longest Flight Route**: Longest path in DAG with topological sort
