# CSES 07 Mathematics Notes

## 1081 - Common Divisors

- **Description**: Find the largest integer d > 0 that divides at least two numbers in the given list.
- **Key Ideas**: Count the frequency of each number, then for each possible divisor d (from largest to smallest), sum the counts of all multiples of d. The first d with count >= 2 is the answer.

## 1082 - Sum of Divisors

- **Description**: Calculate the sum of divisors for all numbers from 1 to n, modulo 1e9+7.
- **Key Ideas**: For each possible quotient q = n // d, sum the contribution of all d with the same quotient using arithmetic progression. Use modular arithmetic for efficiency.

## 1713 - Counting Divisors

- **Description**: For each query, output the number of divisors of x.
- **Key Ideas**: Precompute the number of divisors for all numbers up to 1e6 using a sieve-like approach, then answer each query in O(1).

## 1722 - Fibonacci Numbers

- **Description**: Compute the nth Fibonacci number modulo 1e9+7.
- **Key Ideas**: Use the fast doubling method for Fibonacci numbers to achieve O(log n) time.

## 2164 - Josephus Queries

- **Description**: For each query, find the k-th person to be eliminated in the Josephus problem with n people.
- **Key Ideas**: Use a recursive formula to find the k-th removed person efficiently, exploiting the structure of the Josephus elimination process.

## 2182 - Divisor Analysis

- **Description**: Given a number's prime factorization, calculate the number of divisors, sum of divisors, and product of divisors.
- **Key Ideas**: For a number with prime factorization n = p₁^k₁ × p₂^k₂ × ... × pₘ^kₘ:
  - Number of divisors: ∏(kᵢ + 1)
  - Sum of divisors: ∏((pᵢ^(kᵢ+1) - 1) / (pᵢ - 1))
  - Product of divisors: Use iterative formula to avoid overflow

### Divisor Product Formula (iterative approach):

```
P_i = P_{i-1}^{k_i + 1} × (x_i^{k_i × (k_i + 1) / 2})^{C_{i-1}}
```

Where:

- P_i = product of divisors after processing first i prime factors
- x_i = i-th prime factor
- k_i = exponent of i-th prime factor
- C\_{i-1} = number of divisors from first (i-1) prime factors

This formula works by considering how each new prime factor contributes to the product of all divisors.

## 2185 - Prime Multiples

- **Description**: Count how many integers from 1 to k are divisible by at least one of the given primes.
- **Key Ideas**: Use inclusion-exclusion principle. For each non-empty subset of primes, calculate their product and add/subtract k divided by this product based on the subset size (odd = add, even = subtract).
- **Complexity**: O(2^n) where n ≤ 20, so maximum 2^20 ≈ 1M operations.
