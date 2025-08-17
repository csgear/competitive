# CSES 06 Tree Algorithms Notes

## 1130 - Tree Matching

- **Description**: Find the maximum matching in a tree (maximum number of edges with no common vertices).
- **Key Ideas**: Use dynamic programming on trees. For each node, compute the maximum matching including/excluding the edge to its parent.

## 1131 - Tree Diameter

- **Description**: Find the diameter (longest path) of a tree.
- **Key Ideas**: Use two DFS traversals: first to find the farthest node from any node, then from that node to find the farthest node again. The distance between these two nodes is the diameter.

## 1132 - Tree Distances I

- **Description**: For each node, find the maximum distance to any other node in the tree.
- **Key Ideas**: Find the two endpoints of the diameter using DFS. For each node, its answer is the maximum of its distances to the two endpoints.

## 1133 - Tree Distances II

- **Description**: For each node, find the sum of distances to all other nodes.
- **Key Ideas**: Use post-order DFS to compute subtree sizes and initial distance sums, then pre-order DFS to propagate the results to all nodes efficiently.

## 1135 - Distance Queries

- **Description**: Answer queries about the distance between two nodes in a tree.
- **Key Ideas**: Use LCA (Lowest Common Ancestor) with binary lifting. Distance between nodes u and v is depth[u] + depth[v] - 2 \* depth[lca(u,v)].

## 1137 - Subtree Queries

- **Description**: Process queries on subtrees: update a node's value and query the sum of values in a subtree.
- **Key Ideas**: Use DFS ordering to flatten the tree into an array, then use Fenwick tree for range updates and queries. Each subtree corresponds to a contiguous range.

## 1138 - Path Queries

- **Description**: Process queries on paths from root: update a node's value and query the sum of values on the path from root to a node.
- **Key Ideas**: Use DFS ordering and Fenwick tree with difference technique. Add value at entry time and subtract at exit time to handle path queries efficiently.

## 1674 - Subordinates

- **Description**: For each employee, count the number of subordinates in the company hierarchy tree.
- **Key Ideas**: Use DFS to count the size of each subtree, subtracting one to exclude the node itself.

## 1687 - Company Queries I

- **Description**: Answer queries about the k-th ancestor of a node in a tree.
- **Key Ideas**: Use binary lifting technique. Precompute ancestors at powers of 2 distances, then use binary representation to find k-th ancestor.

## 1688 - Company Queries II

- **Description**: Answer LCA (Lowest Common Ancestor) queries in a tree.
- **Key Ideas**: Use binary lifting for LCA. First bring both nodes to the same level, then binary search for the LCA by lifting both nodes simultaneously.

## 2079 - Finding a Centroid

- **Description**: Find a centroid of a tree (a node whose removal splits the tree into subtrees of at most n/2 nodes).
- **Key Ideas**: Use DFS to compute subtree sizes and for each node, track the size of the largest resulting subtree if that node is removed. The node minimizing this value is a centroid.

## 2080 - Fixed Length Paths I

- **Description**: Count the number of paths in a tree that have exactly k edges.
- **Key Ideas**: Use centroid decomposition. For each centroid, count paths passing through it by combining nodes from different subtrees at complementary distances.

## Key Techniques Summary

### Binary Lifting

- Used for: LCA queries, k-th ancestor queries
- Time: O(log n) per query, O(n log n) preprocessing
- Files: 1687, 1688, 1135

### DFS Ordering / Euler Tour

- Used for: Converting tree problems to array problems
- Applications: Subtree queries, path queries
- Files: 1137, 1138

### Centroid Decomposition

- Used for: Path counting problems, tree divide-and-conquer
- Time: O(n log n) for preprocessing
- Files: 2079, 2080

### Tree DP

- Used for: Optimization problems on trees
- Pattern: Compute optimal solutions for subtrees
- Files: 1130, 1132, 1133
