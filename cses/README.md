# CSES Problem Set

- [Introductory Problems](01_Introductory_Problems/README.md)
- [Sorting and Searching](02_Sorting_and_Searching/README.md)
- [Dynamic Programming](03_Dynamic_Programming/README.md)
- [Graph Algorithms](04_Graph_Algorithms/README.md)
- [Range Queries](05_Range_Queries/README.md)
- [Tree Algorithms](06_Tree_Algorithms/README.md)
- [Mathematics](07_Mathematics/README.md)
- [String Algorithms](08_String_Algorithms/README.md)
- [Geometry](09_Geometry/README.md)
- [Advanced Techniques](10_Advanced_Techniques/README.md)
- [Sliding Window Problems](11_Sliding_Window_Problems/README.md)
- [Interactive Problems](12_Interactive_Problems/README.md)
- [Bitwise Operations](13_Bitwise_Operations/README.md)
- [Construction Problems](14_Construction_Problems/README.md)
- [Advanced Graph Problems](15_Advanced_Graph_Problems/README.md)
- [Counting Problems](16_Counting_Problems/README.md)
- [Additional Problems I](17_Additional_Problems_I/README.md)
- [Additional Problems II](18_Additional_Problems_II/README.md)

## Others

For each digit position $d$ (units, tens, hundreds, ...), split $n$ into:

-
- **higher**: digits to the left of $d$
- **current**: digit at position $d$
- **lower**: digits to the right of $d$

The number of times '5' appears in that position is:

$$
\text{count} = \text{higher} \times \text{factor} +
\begin{cases}
    \text{lower} + 1, & \text{if current digit} = 5 \\
    \text{factor},    & \text{if current digit} > 5 \\
    0,                & \text{if current digit} < 5
\end{cases}
$$

where

$$
\text{factor} = 10^d
$$

### 1073 Fibonacci Numbers

## Fast Doubling Method (Recommended) or or fast matrix exponentiation to compute fibonacci number of n

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
