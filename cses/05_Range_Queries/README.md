# CSES Range Queries Problems

This directory contains solutions to the CSES Range Queries problems. Below is a summary of each problem and the main technique used.

---

## 1646 - Static Range Sum Queries

- **Description:** Answer sum queries on a static array (no updates).
- **Technique:** Prefix sum array for O(1) queries.

## 1647 - Static Range Minimum Queries

- **Description:** Answer minimum queries on a static array (no updates).
- **Technique:** Sparse Table for O(1) queries after O(n log n) preprocessing.

## 1648 - Dynamic Range Sum Queries

- **Description:** Support point updates and range sum queries.
- **Technique:** Segment Tree.

## 1649 - Dynamic Range Minimum Queries

- **Description:** Support point updates and range minimum queries.
- **Technique:** Segment Tree (with or without lazy propagation, depending on update type).

## 1650 - Range XOR Queries

- **Description:** Answer xor queries on a static array (no updates).
- **Technique:** Prefix xor array for O(1) queries.

## 1651 - Range Update Queries

- **Description:** Support range add updates and point queries.
- **Technique:** Segment Tree with lazy propagation.
