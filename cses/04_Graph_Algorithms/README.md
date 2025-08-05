# CSES 04 Graph Algorithms Notes

## 1146 - Counting Bits

- **Description**: (No code provided.)
- **Key Ideas**: (No solution in file.)

## 1192 - Counting Rooms

- **Description**: Count the number of connected empty regions (rooms) in a grid.
- **Key Ideas**: Use DFS or BFS to explore each unvisited empty cell, marking all reachable cells as visited. Each new DFS/BFS call corresponds to a new room.

## 1193 - Labyrinth

- **Description**: Find a path from 'A' to 'B' in a grid, if one exists, and output the path.
- **Key Ideas**: Use BFS to find the shortest path, keeping track of directions to reconstruct the path from 'B' to 'A'.

## 1194 - Monsters

- **Description**: Determine if 'A' can escape a grid before being caught by monsters, and output the escape path if possible.
- **Key Ideas**: Use multi-source BFS: first spread monster times, then try to escape with 'A', ensuring 'A' never enters a cell after or at the same time as a monster.

## 1666 - Building Roads

- **Description**: Connect all cities in a country with the minimum number of new roads.
- **Key Ideas**: Use DFS to find connected components. For each new component, add a road to connect it to the previous one.

## 1667 - Message Route

- **Description**: Find the shortest path from node 1 to node n in an unweighted graph.
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
