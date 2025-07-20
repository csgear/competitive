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
