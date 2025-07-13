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

**Problem**: Count the number of distinct ordered ways to produce a money sum $x$ using available coins (unbounded knapsack).

**DP Formula**:
$$dp[i] = \sum_{j=0}^{n-1} dp[i - values[j]] \quad \text{for} \quad i - values[j] \geq 0$$

**Algorithm**:

- Iterate through coins first, then amounts
- For each coin $values[j]$, update all amounts $\geq values[j]$
- This ensures we count all possible orderings
