# CSES Problem Set Solutions

This directory contains solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), a comprehensive collection of competitive programming problems.

## Problem Categories

| Category                                                  | Problems Solved | Key Topics                                    |
| --------------------------------------------------------- | --------------- | --------------------------------------------- |
| [01 Introductory Problems](01_Introductory_Problems/)     | 26              | Basic algorithms, recursion, bit manipulation |
| [02 Sorting and Searching](02_Sorting_and_Searching/)     | 35              | Binary search, two pointers, sliding window   |
| [03 Dynamic Programming](03_Dynamic_Programming/)         | 25              | DP states, optimization, classical problems   |
| [04 Graph Algorithms](04_Graph_Algorithms/)               | 42              | BFS/DFS, shortest paths, MST, flows, matching |
| [05 Range Queries](05_Range_Queries/)                     | 22              | Segment trees, BIT, lazy propagation          |
| [06 Tree Algorithms](06_Tree_Algorithms/)                 | 5               | Tree DP, LCA, heavy-light decomposition       |
| [07 String Algorithms](07_String_Algorithms/)             | 12              | String matching, hashing, suffix structures   |
| [08 Mathematics](08_Mathematics/)                         | 22              | Number theory, combinatorics, linear algebra  |
| [09 Geometry](09_Geometry/)                               | 3               | Computational geometry, convex hull           |
| [10 Advanced Techniques](10_Advanced_Techniques/)         | 3               | Advanced data structures and algorithms       |
| [11 Sliding Window Problems](11_Sliding_Window_Problems/) | 9               | Two pointers, sliding window technique        |
| [12 Interactive Problems](12_Interactive_Problems/)       | 0               | Interactive problem solving                   |
| [13 Bitwise Operations](13_Bitwise_Operations/)           | 2               | Bit manipulation, subset enumeration          |
| [14 Construction Problems](14_Construction_Problems/)     | 1               | Constructive algorithms                       |
| [15 Advanced Graph Problems](15_Advanced_Graph_Problems/) | 1               | Advanced graph theory                         |
| [16 Counting Problems](16_Counting_Problems/)             | 2               | Inclusion-exclusion, generating functions     |
| [17 Additional Problems I](17_Additional_Problems_I/)     | 2               | Mixed advanced topics                         |
| [18 Additional Problems II](18_Additional_Problems_II/)   | 1               | Mixed advanced topics                         |

## Implementation Notes

### Coding Style

- **Language**: C++ (C++17 standard)
- **Templates**: Consistent use of competitive programming templates
- **Graph Representation**: Adjacency lists using custom Edge structures
- **Data Structures**: STL containers with occasional custom implementations

### Key Algorithms Implemented

- **Graph Algorithms**: Dijkstra, Floyd-Warshall, Bellman-Ford, DFS/BFS variants, Dinic's max flow
- **Dynamic Programming**: Classical DP, digit DP, bitmask DP, tree DP
- **Data Structures**: Segment trees, Binary Indexed Trees (BIT), dynamic segment trees
- **Flow Networks**: Maximum flow, minimum cost flow, bipartite matching, edge-disjoint paths
- **String Algorithms**: KMP, Z-algorithm, hashing, suffix structures
- **Mathematics**: Number theory, combinatorics, matrix exponentiation, linear algebra
- **Tree Algorithms**: Heavy-light decomposition, LCA, tree distances
- **Geometry**: Point location, line intersection, convex operations

## Progress Summary

- **Total Problems**: 300 in CSES Problem Set
- **Problems Solved**: 213 across multiple categories
- **Focus Areas**: Graph algorithms, data structures, dynamic programming, mathematics
- **Completion Rate**: 71% of the problem set

## Usage

Each directory contains:

- Solution files (`*.cpp`)
- Category-specific README with problem explanations
- Implementation notes and complexity analysis

## References

- [CSES Problem Set](https://cses.fi/problemset/)
- [Competitive Programming Handbook](https://cses.fi/book/book.pdf) by Antti Laaksonen

The fast doubling method uses the following recurrence relations:
For even n (n = 2k):
$$F(2k) = F(k) \cdot (2 \cdot F(k+1) - F(k))$$
$$F(2k+1) = F(k+1)^2 + F(k)^2$$

For odd n (n = 2k+1):
$$F(2k+1) = F(k+1)^2 + F(k)^2$$
$$F(2k+2) = F(k+1)^2 + F(k)^2 + 2 \cdot F(k) \cdot F(k+1)$$

Time Complexity:
$$O(\log n)$$
Space Complexity:
$$O(\log n)$$
This method is optimal for computing single Fibonacci numbers with very large indices (up to $10^{18}$).
