# CSES 01 Introductory Problems

This section contains solutions for introductory problems from CSES Problem Set. These problems cover fundamental programming concepts including simulation, mathematics, combinatorics, and basic algorithms.

## Problems Overview

### Mathematical & Arithmetic

| Problem                                            | Algorithm           | Complexity | Key Concepts              |
| -------------------------------------------------- | ------------------- | ---------- | ------------------------- |
| [1068 - Weird Algorithm](1068_weird_algorithm.cpp) | Simulation          | O(log n)   | Collatz conjecture        |
| [1083 - Missing Number](1083_missing_number.cpp)   | Math Formula        | O(n)       | Sum formula               |
| [1617 - Bit Strings](1617_bit_strings.cpp)         | Fast Exponentiation | O(log n)   | Modular arithmetic        |
| [1618 - Trailing Zeros](1618_tailing_zeros.cpp)    | Factor Counting     | O(log n)   | Prime factorization       |
| [1071 - Number Spiral](1071_number_spiral.cpp)     | Pattern Recognition | O(1)       | Mathematical pattern      |
| [1072 - Two Knights](1072_two_knights.cpp)         | Combinatorics       | O(1)       | Counting with constraints |
| [2431 - Digit Queries](2431_digit_queries.cpp)     | Digit Analysis      | O(log n)   | Number representation     |

### Array & String Processing

| Problem                                                  | Algorithm        | Complexity | Key Concepts            |
| -------------------------------------------------------- | ---------------- | ---------- | ----------------------- |
| [1069 - Repetitions](1069_repetitions.cpp)               | Two Pointers     | O(n)       | Longest consecutive     |
| [1094 - Increasing Array](1094_increasing_array.cpp)     | Greedy           | O(n)       | Minimum operations      |
| [1070 - Permutations](1070_permutations.cpp)             | Construction     | O(n)       | Permutation generation  |
| [1092 - Two Sets](1092_two_sets.cpp)                     | Greedy Partition | O(n)       | Set partitioning        |
| [1754 - Coin Piles](1754_coin_piles.cpp)                 | Game Theory      | O(1)       | Mathematical condition  |
| [1755 - Palindrome Reorder](1755_palindrome_reorder.cpp) | Frequency Count  | O(n)       | Character rearrangement |

### Backtracking & Recursion

| Problem                                                        | Algorithm              | Complexity | Key Concepts       |
| -------------------------------------------------------------- | ---------------------- | ---------- | ------------------ |
| [1622 - Creating Strings](1622_create_strings.cpp)             | Permutation            | O(n! × n)  | All permutations   |
| [1623 - Apple Division](1623_apple_division.cpp)               | Bitmask                | O(2^n × n) | Subset enumeration |
| [1624 - Chessboard and Queens](1624_chessboard_and_queen.cpp)  | Backtracking           | O(n!)      | N-Queens problem   |
| [1625 - Grid Path Description](1625_grid_path_description.cpp) | DFS + Pruning          | O(4^path)  | Path counting      |
| [2165 - Tower of Hanoi](2165_tower_of_hanoi.cpp)               | Recursion              | O(2^n)     | Classic recursion  |
| [2205 - Gray Code](2205_gray_code.cpp)                         | Recursive Construction | O(2^n)     | Binary sequences   |

### Advanced & Contest Problems

| Problem                                                                      | Algorithm           | Complexity | Key Concepts          |
| ---------------------------------------------------------------------------- | ------------------- | ---------- | --------------------- |
| [3217 - Knight Moves Grid](3217_knight_moves_grid.cpp)                       | BFS                 | O(n²)      | Shortest path on grid |
| [3311 - Grid Coloring](3311_grid_coloring.cpp)                               | Greedy              | O(n²)      | Graph coloring        |
| [3399 - Raab Game I](3399_raab_game_1.cpp)                                   | Game Theory         | O(n)       | Optimal strategy      |
| [3419 - MEX Grid Construction](3419_mex_grid_construction.cpp)               | Greedy Construction | O(n³)      | MEX calculation       |
| [3420 - Distinct Values Subarrays](3420_distinct_values_subarrays.cpp)       | Sliding Window      | O(n)       | Subarray counting     |
| [3421 - Distinct Values Subsequences](3421_distinct_values_subsequences.cpp) | Combinatorics       | O(n)       | Subsequence counting  |
| [1743 - String Reorder](1743_string_reoder.cpp)                              | Backtracking        | O(26^n)    | Constrained ordering  |

## Algorithm Categories

### **Mathematical Foundations**

- **Number Theory**: GCD, modular arithmetic, prime factorization
- **Combinatorics**: Counting principles, binomial coefficients
- **Pattern Recognition**: Finding mathematical relationships
- **Formula Derivation**: Converting problems to closed-form solutions

### **Basic Algorithms**

- **Two Pointers**: Linear scan with two indices
- **Greedy Approach**: Local optimal choices
- **Simulation**: Direct implementation of problem rules
- **Construction**: Building solutions step by step

### **Backtracking Techniques**

- **State Space Search**: Systematic exploration
- **Pruning**: Early termination of invalid paths
- **Constraint Satisfaction**: N-Queens, path problems
- **Enumeration**: Generating all valid solutions

### **Advanced Concepts**

- **Game Theory**: Optimal strategies, winning conditions
- **Graph Algorithms**: BFS for shortest paths
- **Data Structure Applications**: MEX calculation, frequency counting

## Key Implementation Patterns

### 1. Fast Exponentiation

```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

### 2. Backtracking Template

```cpp
bool solve(int position, vector<int>& solution) {
    if (position == n) {
        return isValidSolution(solution);
    }

    for (int choice : possibleChoices(position)) {
        if (isValidChoice(position, choice, solution)) {
            solution[position] = choice;
            if (solve(position + 1, solution)) {
                return true;
            }
            // Backtrack
            solution[position] = -1;
        }
    }
    return false;
}
```

### 3. Two Pointers for Consecutive Elements

```cpp
int maxConsecutive = 1, current = 1;
for (int i = 1; i < n; i++) {
    if (s[i] == s[i-1]) {
        current++;
    } else {
        maxConsecutive = max(maxConsecutive, current);
        current = 1;
    }
}
maxConsecutive = max(maxConsecutive, current);
```

### 4. Bitmask Enumeration

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            sum += arr[i];
        }
    }
    // Process this subset
}
```

## Problem-Solving Insights

1. **Mathematical Thinking**: Look for patterns, formulas, and closed-form solutions
2. **Edge Case Handling**: Consider small inputs and boundary conditions
3. **Complexity Analysis**: Choose appropriate algorithms based on constraints
4. **Backtracking Optimization**: Use pruning to avoid unnecessary computation
5. **Pattern Recognition**: Many problems have underlying mathematical structures
6. **Greedy Validation**: Verify that greedy choices lead to optimal solutions
7. **Combinatorial Analysis**: Use counting principles for enumeration problems

## Common Problem Types

### **Simulation Problems**

- Direct implementation of given rules
- Step-by-step execution until termination condition

### **Construction Problems**

- Build solution incrementally
- Often require mathematical insight or greedy approach

### **Counting Problems**

- Enumerate all valid configurations
- Use combinatorial formulas when possible

### **Optimization Problems**

- Find minimum/maximum value
- Often solvable with greedy or mathematical analysis
