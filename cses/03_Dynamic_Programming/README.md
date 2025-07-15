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

###
