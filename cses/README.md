# CSES Problem Set Solutions

This directory contains solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), a comprehensive collection of competitive programming problems.

## Problem Categories

| Category                                                  | Problems Solved | Key Topics                                    |
| --------------------------------------------------------- | --------------- | --------------------------------------------- |
| [01 Introductory Problems](01_Introductory_Problems/)     | 20+             | Basic algorithms, recursion, bit manipulation |
| [02 Sorting and Searching](02_Sorting_and_Searching/)     | -               | Binary search, two pointers, sliding window   |
| [03 Dynamic Programming](03_Dynamic_Programming/)         | -               | DP states, optimization, classical problems   |
| [04 Graph Algorithms](04_Graph_Algorithms/)               | 25+             | BFS/DFS, shortest paths, MST, flows, matching |
| [05 Range Queries](05_Range_Queries/)                     | 5+              | Segment trees, BIT, lazy propagation          |
| [06 Tree Algorithms](06_Tree_Algorithms/)                 | -               | Tree DP, LCA, heavy-light decomposition       |
| [07 Mathematics](07_Mathematics/)                         | -               | Number theory, combinatorics, linear algebra  |
| [08 String Algorithms](08_String_Algorithms/)             | -               | String matching, hashing, suffix structures   |
| [09 Geometry](09_Geometry/)                               | -               | Computational geometry, convex hull           |
| [10 Advanced Techniques](10_Advanced_Techniques/)         | -               | Advanced data structures and algorithms       |
| [11 Sliding Window Problems](11_Sliding_Window_Problems/) | -               | Two pointers, sliding window technique        |
| [12 Interactive Problems](12_Interactive_Problems/)       | -               | Interactive problem solving                   |
| [13 Bitwise Operations](13_Bitwise_Operations/)           | -               | Bit manipulation, subset enumeration          |
| [14 Construction Problems](14_Construction_Problems/)     | -               | Constructive algorithms                       |
| [15 Advanced Graph Problems](15_Advanced_Graph_Problems/) | -               | Advanced graph theory                         |
| [16 Counting Problems](16_Counting_Problems/)             | -               | Inclusion-exclusion, generating functions     |
| [17 Additional Problems I](17_Additional_Problems_I/)     | -               | Mixed advanced topics                         |
| [18 Additional Problems II](18_Additional_Problems_II/)   | -               | Mixed advanced topics                         |

## Implementation Notes

### Coding Style

- **Language**: C++ (C++17 standard)
- **Templates**: Consistent use of competitive programming templates
- **Graph Representation**: Adjacency lists using custom Edge structures
- **Data Structures**: STL containers with occasional custom implementations

### Key Algorithms Implemented

- **Graph Algorithms**: Dijkstra, Floyd-Warshall, Bellman-Ford, DFS/BFS variants
- **Tree Algorithms**: Heavy-light decomposition, segment trees with lazy propagation
- **Flow Networks**: Maximum flow, minimum cost flow, bipartite matching
- **Advanced Structures**: Binary Indexed Trees (BIT), dynamic segment trees

## Progress Summary

- **Total Problems**: 300 in CSES Problem Set
- **Problems Solved**: 50+ across multiple categories
- **Focus Areas**: Graph algorithms, data structures, dynamic programming

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
