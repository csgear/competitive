## Notes

## Counting the number of '5's in 1 to n

For each digit position $d$ (units, tens, hundreds, ...), split $n$ into:

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
