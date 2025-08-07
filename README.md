# Competitive Programming Solutions

A comprehensive collection of competitive programming solutions from various online judges and contests.

## 📊 Progress Overview

| Platform         | Problems Solved | Key Achievements                                                      |
| ---------------- | --------------- | --------------------------------------------------------------------- |
| **CSES**         | **80+**         | Dynamic Programming (24), Sliding Window (15), String Algorithms (12) |
| **Luogu**        | **25+**         | Advanced algorithms, Chinese contest problems                         |
| **USACO**        | **15+**         | Contest preparation, algorithmic problem solving                      |
| **AtCoder**      | **10+**         | ABC and other contest problems                                        |
| **AdventOfCode** | **5+**          | 2024 contest problems                                                 |
| **CCC**          | **15+**         | Canadian Computing Competition                                        |

## 🏆 Recent Achievements

- ✅ **CSES Dynamic Programming**: Completed 24/19 problems including advanced techniques

  - Mountain Range (3314) - Monotonic stack + Segment tree optimization
  - Counting Numbers (2220) - Digit DP with memoization
  - Projects (1140) - Weighted job scheduling with binary search
  - Counting Towers (2413) - State-based DP with combinatorial structures

- ✅ **Advanced Algorithms Implemented**:
  - Segment Tree templates (multiple variants)
  - Digit Dynamic Programming
  - Monotonic Stack applications
  - Binary search optimizations
  - Weighted interval scheduling

## 🗂️ Repository Structure

### CSES Problem Set

```
cses/
├── 01_Introductory_Problems/     # Basic problems and implementation
├── 02_Sorting_and_Searching/     # Algorithms and data structures
├── 03_Dynamic_Programming/       # ✅ 24/19 problems - COMPLETED
├── 04_Graph_Algorithms/          # Graph theory problems
├── 05_Range_Queries/             # Segment trees, BIT, etc.
├── 06_Tree_Algorithms/           # Tree-based problems
├── 07_Mathematics/               # Number theory, combinatorics
├── 08_String_Algorithms/         # ✅ String processing - COMPLETED
├── 09_Geometry/                  # Computational geometry
├── 10_Advanced_Techniques/       # Advanced algorithmic techniques
├── 11_Sliding_Window_Problems/   # ✅ Sliding window - COMPLETED
├── 12_Interactive_Problems/      # Interactive problem solving
├── 13_Bitwise_Operations/        # Bit manipulation
├── 14_Construction_Problems/     # Constructive algorithms
├── 15_Advanced_Graph_Problems/   # Complex graph algorithms
├── 16_Counting_Problems/         # Combinatorial counting
├── 17_Additional_Problems_I/     # Mixed advanced problems
└── 18_Additional_Problems_II/    # More challenging problems
```

### Other Platforms

```
├── luogu/              # Chinese competitive programming platform
├── usaco/              # USA Computing Olympiad problems
├── abc/               # AtCoder Beginner Contest problems
├── ccc/               # Canadian Computing Competition
├── adventofcode/      # Advent of Code annual challenges
├── journey/           # Learning path and practice problems
└── templates/         # Reusable algorithm templates
```

## 🔧 Algorithm Templates

### Segment Tree (Optimized for DP)

```cpp
const int MAXN = 2e5 + 5;
int tree[MAXN << 2];

void push_up(int p) {
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

void update(int p, int pl, int pr, int pos, int val) { /* ... */ }
int query(int p, int pl, int pr, int l, int r) { /* ... */ }
```

### Digit Dynamic Programming

```cpp
string num;
int dp[20][10][2][2]; // pos, lastDigit, tight, started

int solve(int pos, int last, bool tight, bool started) { /* ... */ }
```

### Monotonic Stack (Nearest Greater Elements)

```cpp
vector<int> L(n, -1), R(n, n);
stack<int> st;

// Find nearest greater on left and right
for (int i = 0; i < n; i++) { /* ... */ }
```

## 📈 Key Algorithmic Topics Mastered

- **Dynamic Programming**: Linear, grid, string, interval, bitmask, digit DP
- **Data Structures**: Segment trees, Fenwick trees, monotonic stacks/queues
- **Graph Algorithms**: DFS, BFS, shortest paths, MST, topological sort
- **String Processing**: KMP, Z-algorithm, suffix arrays, string hashing
- **Number Theory**: Prime sieves, GCD, modular arithmetic, combinatorics
- **Optimization**: Binary search, two pointers, sliding window techniques

## 🎯 Current Focus

- **CSES Range Queries**: Segment tree variants and applications
- **CSES Graph Algorithms**: Advanced graph theory problems
- **Algorithm Optimization**: Converting O(n³) solutions to O(n log n)
- **Contest Preparation**: Regular practice and template refinement

## 📝 Problem-Solving Approach

1. **Pattern Recognition**: Identify algorithm types and optimal approaches
2. **Template Usage**: Leverage tested, optimized code templates
3. **Complexity Analysis**: Ensure solutions meet time/space constraints
4. **Code Quality**: Clean, readable implementations with proper documentation
5. **Continuous Learning**: Regular upskilling with advanced techniques

---

_Last Updated: August 2025 | Total Problems: 150+ across multiple platforms_
