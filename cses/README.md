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
