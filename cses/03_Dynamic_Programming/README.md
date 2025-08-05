## CSES Problem Set - Dynamic Programming

### 1633 Dice Combinations

$$dp[i] = dp[i] + \sum_{j=1}^{6} dp[i-j] \quad \text{for} \quad i-j \geq 0$$

### 1634 Minimizing Coins

$$dp[i] = \min_{j: coins[j] \leq i} \{dp[i - coins[j]] + 1\}$$

### 1635 Coin Combinations I

$$dp[i] = \sum_{j=0}^{n-1} dp[i - values[j]] \quad \text{for} \quad i - values[j] \geq 0$$

where:

- Base case: `dp[0] = 1` (one way to make sum 0: use no coins)

### 1636 Coin Combinations II

**DP Formula**:
$$dp[i] = \sum_{j=0}^{n-1} dp[i - values[j]] \quad \text{for} \quad i - values[j] \geq 0$$

**Algorithm**:

- Iterate through coins first, then amounts
- For each coin $values[j]$, update all amounts $\geq values[j]$
- This ensures we count all possible orderings

### 1637 Removing digits

try every digit of i for i from 1 to n, dp[0] = 0

### 1638 Grid Path I

only can go right and down, so dp[i][j] = dp[i-1][j] + dp[i][j-1]

for base case dp[0][0] = 0 or 1 if dp[0][0] = '\*'

### 1158 Book Shop

Classic 0/1 knapsack problem

## Detailed Problem Explanations

### 2413 - Counting Towers

**Problem Type**: State-based DP

This is a combinatorial DP problem that counts the number of ways to build towers with structural constraints.

**State Definition**:

- `dp[i][0]`: Number of ways to fill first `i` rows ending with **one merged 2×1 block**
- `dp[i][1]`: Number of ways to fill first `i` rows ending with **two separate 1×1 blocks**

**Visual Representation**:

![State Transitions](https://cses.fi/file/477c37c3fb6e8fb2dfd150ebfec2dd20337508b3bf25e11b54d9e7cf651ecdac)

_Source: [CSES Counting Towers Problem](https://cses.fi/file/477c37c3fb6e8fb2dfd150ebfec2dd20337508b3bf25e11b54d9e7cf651ecdac)_

**State Transitions** (as shown in diagram):

**Transition Formula**:

```
dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]) % MOD
dp[i][1] = (dp[i-1][0] + 4 * dp[i-1][1]) % MOD
```

### 1744 - Rectangle Cutting

**Problem Type**: 2D Interval DP

Find minimum cuts to divide `a × b` rectangle into unit squares.

**State**: `dp[i][j]` = minimum cuts for `i × j` rectangle
**Base**: `dp[i][i] = 0` (squares need no cuts)
**Transitions**: Try all horizontal and vertical cuts

### 1639 - Edit Distance

**Problem Type**: Classic DP

Minimum edit distance (Levenshtein) between two strings.

**State**: `dp[i][j]` = min operations to transform `s1[0..i-1]` to `s2[0..j-1]`
**Operations**: Insert, delete, substitute
