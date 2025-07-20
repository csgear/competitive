# CSES 08 String Algorithms Notes

## 1111 - Longest Palindrome

- **Description**: Find the longest palindromic substring in a given string.
- **Key Ideas**: Use Manacher's algorithm for linear time palindrome detection, or expand around center for O(n^2) solution. Manacher's algorithm is preferred for efficiency.

## 1731 - String Matching

- **Description**: Given a text and several patterns, count how many times each pattern appears in the text.
- **Key Ideas**: Use the Aho-Corasick automaton (AC automaton) for multi-pattern matching in linear time. Build a trie of patterns, compute failure links, and process the text in one pass.

## 1733 - Finding Periods

- **Description**: Find all periods of a given string. A period is a length p such that the string can be constructed by repeating its prefix of length p.
- **Key Ideas**: Use the KMP algorithm's "next array" (failure function) to efficiently compute the borders of the string. The borders correspond to possible periods, and you can extract all periods by traversing the failure function.
