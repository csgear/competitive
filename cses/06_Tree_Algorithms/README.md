# CSES 06 Tree Algorithms Notes

## 1131 - Tree Diameter

- **Description**: Find the diameter (longest path) of a tree.
- **Key Ideas**: Use two DFS traversals: first to find the farthest node from any node, then from that node to find the farthest node again. The distance between these two nodes is the diameter.

## 1132 - Tree Distances I

- **Description**: For each node, find the maximum distance to any other node in the tree.
- **Key Ideas**: Find the two endpoints of the diameter using DFS. For each node, its answer is the maximum of its distances to the two endpoints.

## 1133 - Tree Distances II

- **Description**: For each node, find the sum of distances to all other nodes.
- **Key Ideas**: Use post-order DFS to compute subtree sizes and initial distance sums, then pre-order DFS to propagate the results to all nodes efficiently.

## 1674 - Subordinates

- **Description**: For each employee, count the number of subordinates in the company hierarchy tree.
- **Key Ideas**: Use DFS to count the size of each subtree, subtracting one to exclude the node itself.

## 2079 - Finding a Centroid

- **Description**: Find a centroid of a tree (a node whose removal splits the tree into subtrees of at most n/2 nodes).
- **Key Ideas**: Use DFS to compute subtree sizes and for each node, track the size of the largest resulting subtree if that node is removed. The node minimizing this value is a centroid.
