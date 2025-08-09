# CSES 08 Mathematics Notes

## 1079 - Binomial Coefficients

- **Description**: Calculate n binomial coefficients C(a,b) modulo 10^9+7.
- **Key Ideas**: Precompute factorials and their modular inverses using Fermat's Little Theorem. C(a,b) = a! / (b! × (a-b)!) mod p.
- **Algorithm**: Use modular exponentiation to compute factorial inverses, then answer each query in O(1).
- **Complexity**: O(max_a) preprocessing, O(1) per query.

## 1081 - Common Divisors

- **Description**: Find the largest integer d > 0 that divides at least two numbers in the given list.
- **Key Ideas**: Count the frequency of each number, then for each possible divisor d (from largest to smallest), sum the counts of all multiples of d. The first d with count >= 2 is the answer.

## 1082 - Sum of Divisors

- **Description**: Calculate the sum of divisors for all numbers from 1 to n, modulo 1e9+7.
- **Key Ideas**: For each possible quotient q = n // d, sum the contribution of all d with the same quotient using arithmetic progression. Use modular arithmetic for efficiency.

## 1095 - Exponentiation

- **Description**: Calculate a^b mod (10^9+7) for multiple queries.
- **Key Ideas**: Use fast exponentiation (binary exponentiation) to compute powers in O(log b) time.
- **Algorithm**: Repeatedly square the base and halve the exponent, multiplying result when exponent is odd.
- **Complexity**: O(log b) per query.

## 1096 - Exponentiation II

- **Description**: Calculate a^(b^c) mod (10^9+7) for multiple queries.
- **Key Ideas**: Use Euler's theorem: a^φ(m) ≡ 1 (mod m) when gcd(a,m)=1. Since φ(10^9+7) = 10^9+6, compute b^c mod (10^9+6) first.
- **Algorithm**: Two-level exponentiation with modular arithmetic.
- **Complexity**: O(log c + log b) per query.

## 1713 - Counting Divisors

- **Description**: For each query, output the number of divisors of x.
- **Key Ideas**: Precompute the number of divisors for all numbers up to 1e6 using a sieve-like approach, then answer each query in O(1).

## 1715 - Creating Strings II

- **Description**: Count the number of distinct strings that can be formed using given characters, considering character frequencies.
- **Key Ideas**: Use multinomial coefficients. For string of length n with character frequencies f₁,f₂,...,fₖ: answer = n! / (f₁! × f₂! × ... × fₖ!).
- **Algorithm**: Precompute factorials and their inverses, then use formula for each query.
- **Complexity**: O(alphabet_size) preprocessing, O(k) per query where k is number of distinct characters.

## 1716 - Distributing Apples

- **Description**: Count ways to distribute n identical apples among m children.
- **Key Ideas**: Stars and bars combinatorial problem. Answer = C(n+m-1, m-1) = C(n+m-1, n).
- **Algorithm**: Use precomputed binomial coefficients.
- **Complexity**: O(1) after factorial preprocessing.

## 1717 - Christmas Party

- **Description**: Calculate the number of derangements of n people (permutations where no person sits in their original position).
- **Key Ideas**: Use derangement recurrence: D(n) = (n-1) × [D(n-1) + D(n-2)] with D(0)=1, D(1)=0.
- **Algorithm**: Iterative computation using the recurrence relation.
- **Complexity**: O(n) per query.

## 1729 - Stick Game

- **Description**: Two-player game where players alternate removing sticks from a heap. Determine for each heap size 1 to n whether the first player has a winning or losing position.
- **Key Ideas**: Use Grundy numbers (Sprague-Grundy theorem). A position has Grundy number 0 if and only if it's a losing position.
- **Algorithm**:
  - Grundy(i) = MEX{Grundy(i-p) | p ∈ allowed_moves, i ≥ p}
  - MEX (minimum excludant) = smallest non-negative integer not in the set
  - Position is losing ⟺ Grundy number = 0
- **Game Theory**: Classic impartial game demonstrating the Sprague-Grundy theorem for combinatorial game theory.
- **Complexity**: O(n × k) where k is number of allowed moves.

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

## 3397 - Permutation Order

- **Description**: Convert between a permutation and its lexicographic rank. Two types of queries: (1) Given n and k, find the k-th permutation, (2) Given n and a permutation, find its rank.
- **Key Ideas**: Use factorial number system (Lehmer code). For rank→permutation: repeatedly divide by factorials and pick elements. For permutation→rank: count how many unused elements are smaller than current element.
- **Algorithm**:
  - Rank to permutation: For each position, determine which available element to place by dividing remaining rank by (n-i-1)!
  - Permutation to rank: For each element, count smaller unused elements and multiply by (n-i-1)!
- **Implementation 1** (`3397_permutation_order.cpp`): Basic O(n²) solution using vector operations
- **Implementation 2** (`3397_permutation_order_cantor.cpp`): Optimized O(n log n) using 康托展开 (Cantor Expansion) with BIT
- **Complexity**: O(n²) for basic version, O(n log n) for BIT-optimized version.
