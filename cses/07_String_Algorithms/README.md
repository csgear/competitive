# CSES 08 String Algorithms

This section contains solutions for string algorithm problems from CSES Problem Set. These problems cover fundamental string processing techniques including pattern matching, palindromes, and advanced string structures.

## Problems Overview

### Pattern Matching & Searching

| Problem                                                                | Algorithm        | Complexity   | Key Concepts              |
| ---------------------------------------------------------------------- | ---------------- | ------------ | ------------------------- |
| [1753 - String Matching](1753_string_matching.cpp)                     | KMP              | O(n + m)     | Pattern matching          |
| [1753 - String Matching (Hash)](1753_string_matching_bkdr_hashing.cpp) | Rolling Hash     | O(n + m)     | Hash-based matching       |
| [1753 - String Matching (Z)](1753_string_matching_z_algo.cpp)          | Z Algorithm      | O(n + m)     | Linear pattern matching   |
| [2102 - Finding Patterns (AC)](2102_find_patterns_ac_automaton.cpp)    | Aho-Corasick     | O(n + m + z) | Multiple pattern matching |
| [2102 - Finding Patterns (SA)](2102_find_patterns_suffix_array.cpp)    | Suffix Array     | O(n log n)   | Suffix-based search       |
| [2103 - Counting Patterns](2103_counting_patterns.cpp)                 | Pattern Counting | O(n + m)     | Multiple occurrences      |
| [2104 - Pattern Positions](2104_pattern_positions.cpp)                 | Position Finding | O(n + m)     | All occurrence positions  |

### String Properties & Structure

| Problem                                                  | Algorithm            | Complexity | Key Concepts         |
| -------------------------------------------------------- | -------------------- | ---------- | -------------------- |
| [1111 - Longest Palindrome](1111_longest_palindrome.cpp) | Manacher's Algorithm | O(n)       | Palindrome detection |
| [1732 - Finding Borders](1732_finding_borders.cpp)       | KMP Failure Function | O(n)       | Border computation   |
| [1733 - Finding Periods](1733_finding_periods.cpp)       | Period Analysis      | O(n)       | String periodicity   |

### Dynamic Programming on Strings

| Problem                                                | Algorithm | Complexity | Key Concepts         |
| ------------------------------------------------------ | --------- | ---------- | -------------------- |
| [1731 - Word Combinations](1731_word_combinations.cpp) | DP + Trie | O(n² + m)  | String decomposition |

## Algorithm Categories

### **Pattern Matching Algorithms**

- **KMP (Knuth-Morris-Pratt)**: Linear time pattern matching with failure function
- **Z Algorithm**: Linear time string matching using Z-array
- **Rolling Hash**: Hash-based pattern matching with collision handling
- **Aho-Corasick**: Multiple pattern matching automaton

### **Advanced String Structures**

- **Suffix Arrays**: Efficient substring queries and pattern searching
- **Tries**: Prefix trees for string decomposition and matching
- **Failure Functions**: Border computation for string analysis

### **String Properties**

- **Palindromes**: Manacher's algorithm for linear palindrome detection
- **Borders**: Longest proper prefix-suffix matches
- **Periods**: String repetition patterns and periodicity

## Key Implementation Patterns

### 1. KMP Algorithm with Failure Function

```cpp
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;  // i for text, j for pattern

    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }

        if (j == pattern.length()) {
            // Pattern found at index i-j
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}
```

### 2. Z Algorithm

```cpp
vector<int> zAlgorithm(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```

### 3. Rolling Hash

```cpp
const int MOD = 1e9 + 7;
const int BASE = 31;

long long computeHash(string s) {
    long long hash = 0;
    long long pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * pow) % MOD;
        pow = (pow * BASE) % MOD;
    }
    return hash;
}

vector<long long> rollingHash(string s) {
    int n = s.length();
    vector<long long> hash(n + 1, 0);
    vector<long long> pow(n + 1, 1);

    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * pow[i]) % MOD;
        pow[i + 1] = (pow[i] * BASE) % MOD;
    }
    return hash;
}
```

### 4. Manacher's Algorithm for Palindromes

```cpp
string preprocess(string s) {
    string result = "^";
    for (char c : s) {
        result += "#" + string(1, c);
    }
    result += "#$";
    return result;
}

string longestPalindrome(string s) {
    string T = preprocess(s);
    int n = T.length();
    vector<int> P(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            P[i] = min(right - i, P[mirror]);
        }

        // Try to expand palindrome centered at i
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        // Update center and right boundary
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    // Find longest palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
```

### 5. Trie for Word Combinations

```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    vector<int> findWords(string s, int pos) {
        vector<int> lengths;
        TrieNode* curr = root;

        for (int i = pos; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (!curr->children[idx]) break;
            curr = curr->children[idx];
            if (curr->isEnd) {
                lengths.push_back(i - pos + 1);
            }
        }
        return lengths;
    }
};
```

## Problem-Solving Insights

1. **Algorithm Selection**: Choose based on pattern count and text length
2. **Preprocessing**: Many algorithms benefit from string preprocessing
3. **Linear Time**: Prefer O(n) algorithms like KMP, Z-algorithm, Manacher's
4. **Multiple Patterns**: Use Aho-Corasick for multiple pattern matching
5. **Hash Collisions**: Handle carefully in rolling hash implementations
6. **Border Properties**: Understand prefix-suffix relationships for KMP
7. **Palindrome Structure**: Manacher's algorithm exploits palindrome symmetry

## Advanced Techniques

### **Suffix Arrays**

- Build suffix array with radix sort or DC3 algorithm
- Use for efficient substring queries and pattern matching
- Combine with LCP array for advanced string analysis

### **Aho-Corasick Automaton**

- Build trie of all patterns
- Add failure links for efficient transitions
- Process text in single pass for all patterns

### **String Hashing**

- Use polynomial rolling hash for fast comparisons
- Handle hash collisions with double hashing
- Useful for substring matching and comparison

## Common Problem Patterns

### **Single Pattern Matching**

- KMP for exact matching with linear preprocessing
- Z-algorithm for simpler implementation
- Rolling hash for average-case efficiency

### **Multiple Pattern Matching**

- Aho-Corasick for simultaneous pattern search
- Suffix array with binary search for multiple queries

### **String Properties**

- Manacher's for palindrome problems
- KMP failure function for borders and periods
- DP on tries for word decomposition problems
