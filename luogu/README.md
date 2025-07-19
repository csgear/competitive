# Luogu Problem Solutions

## Dynamic Programming

### P1002 过河卒 (Crossing the River)

Path counting with obstacles. Use 2D DP where `dp[i][j]` represents number of ways to reach position (i,j). Mark knight-controlled squares as blocked, then fill DP table with `dp[i][j] = dp[i-1][j] + dp[i][j-1]`.

### P1004 方格取数 (Grid Number Taking)

Classic DP problem with two paths. Use 4D DP or optimize to 3D: `dp[step][x1][x2]` where step is the number of moves, x1 and x2 are x-coordinates of two paths. Add values if paths don't overlap.

## Simulation & Implementation

### P1003 铺地毯 (Carpet Laying)

Layer simulation problem. Check point (x,y) against each carpet rectangle in order. The last carpet that covers the point is the answer, or -1 if no carpet covers it.

### P1008 三连击 (Triple Strike)

Brute force enumeration. Generate all 3-digit numbers using digits 1-9 without repetition, check if 2×abc and 3×abc also use all remaining digits exactly once.

### P1010 幂次 (Power Representation)

Recursive number theory problem. Express numbers as sum of powers of 2, then recursively express the exponents themselves in the same format.

### P1016 旅行家的预算 (Traveler's Budget)

Greedy simulation of fuel management. At each gas station, decide whether to refuel based on upcoming stations and current fuel. Choose stations with cheapest prices when possible.

### P1018 乘积最大 (Maximum Product)

Dynamic programming on intervals. For each substring, try all possible split points and track maximum products. Handle both positive and negative numbers carefully.

### P1025 数的划分 (Number Partitioning)

Integer partition DP. `dp[i][j]` = number of ways to partition number i using integers ≤ j. Recurrence: `dp[i][j] = dp[i][j-1] + dp[i-j][j]`.

## Mathematical Problems

### P1006 传纸条 (Passing Notes)

Multi-path DP problem similar to P1004. Two people walk from (1,1) to (n,m) simultaneously, maximizing total score while avoiding overlapping paths.

### P1012 拼数 (Number Concatenation)

Custom sorting problem. Sort numbers by comparing their concatenated results: compare (a+b) vs (b+a) as strings to determine optimal ordering.

### P1020 导弹拦截 (Missile Defense)

Longest Decreasing Subsequence (LDS) problem. Use binary search optimization or simple DP to find the length of longest non-increasing subsequence.

### P1024 一元三次方程求解 (Cubic Equation)

Numerical methods with binary search. Since function is continuous, use interval bisection to find roots where f(x) changes sign.

### P1031 均分纸牌 (Card Distribution)

Greedy difference array problem. Calculate target average, then greedily move cards between adjacent positions to minimize total moves.

## Graph Theory & Search

### P1089 津津的储蓄计划 (Savings Plan)

Simulation problem. Track monthly budget, check if expenses can be covered, accumulate savings, and calculate final amount with interest.

### P1090 合并果子 (Merging Fruits)

Priority queue (min-heap) greedy problem. Always merge the two smallest piles to minimize total cost, similar to Huffman coding.

### P1091 合唱队形 (Choir Formation)

Longest Increasing Subsequence variant. For each position, calculate LIS ending at that position and LIS starting from that position, find maximum total length.

## String & Array Processing

### P1100 高低位交换 (High-Low Bit Swap)

Bit manipulation. Swap higher and lower bits of a number, typically involving bit shifts and masking operations.

### P1102 A-B 数对

Two pointers or binary search problem. Count pairs (i,j) where a[i] - a[j] = C. Sort array first, then use efficient searching techniques.

### P1127 词链 (Word Chain)

Eulerian path in directed graph. Build graph where each word is an edge from first character to last character. Find Eulerian path if it exists.

### P1134 阶乘问题 (Factorial Problem)

Number theory with factorial. Calculate properties of n! such as trailing zeros, digit sums, or specific digit patterns.

## Advanced Topics

### P3152 正整数序列 (Adhoc)

log<sub>2</sub>(n) + 1

### P3304 树的直径 (Tree Diameter)

### P3366 最小生成树 (Minimum Spanning Tree)

Graph theory classic. Use Kruskal's algorithm with Union-Find or Prim's algorithm with priority queue to find MST of weighted graph.
