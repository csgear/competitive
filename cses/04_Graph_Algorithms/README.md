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
