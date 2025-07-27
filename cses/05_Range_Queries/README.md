# CSES Range Queries Problems

## 1646 - Static Range Sum Queries

- Prefix sum array for O(1) queries or Segment Tree for range queries.

## 1647 - Static Range Minimum Queries

- Segment Tree

## 1648 - Dynamic Range Sum Queries

- Segment Tree with point update.

## 1649 - Dynamic Range Minimum Queries

- Segment Tree (with or without lazy propagation, depending on update type).

## 1650 - Range XOR Queries

- Prefix XOR for O(1) queries.

## 2206 - Pizzeria Queries

Range minimum query problem with distance-based costs. For a person at position k ordering from pizzeria a, the cost is p[a] + |a - k|.

Key insight: Split the absolute value into two cases:

- Left case (a ≤ k): cost = k + (p[a] - a)
- Right case (a ≥ k): cost = (p[a] + a) - k

Use two segment trees: one storing p[i] - i for left queries, another storing p[i] + i for right queries. For each query, find minimum from both trees and take the smaller result.

Time complexity: O((n + q) log n) for preprocessing and queries.

- Prefix xor array for O(1) queries.

## 1651 - Range Update Queries

- Segment Tree with lazy propagation.

## 1652 - Forest Queries

- 2D Prefix Sum array for O(1) queries.

## 1143 - Hotel Queries

- Segment Tree for range maximum and point updates.

## 1749 - List Removals

- Segment Tree for order statistics (k-th one removal).

## 1144 - Salary Queries

- Segment Tree with coordinate compression and frequency counting.

## 2166 - Prefix Sum Queries

- Segment Tree storing total sum and maximum prefix sum per node.

## 1190 - Subarray Sum Queries

- Segment Tree storing total sum, maximum prefix sum, maximum suffix sum, and maximum subarray sum per node.
