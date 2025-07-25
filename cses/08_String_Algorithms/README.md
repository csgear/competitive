# CSES 08 String Algorithms Notes

## 1111 - Longest Palindrome

Use Manacher's algorithm for linear time palindrome detection, or expand around center for O(n^2) solution. Manacher's algorithm is preferred for efficiency.

## 1731 - Word Combinations

Dynamic programming with trie optimization. Use DP where dp[i] = number of ways to form string[0..i-1]. For efficiency, use trie to find all words starting at each position instead of checking each word separately.

## 1732 - Finding Borders

Use KMP failure function to find the longest border, then follow the failure function chain to find all shorter borders. Each value in the chain represents a border length.

## 1733 - Finding Periods

Use the KMP algorithm's "next array" (failure function) to efficiently compute the borders of the string. The borders correspond to possible periods, and you can extract all periods by traversing the failure function.
