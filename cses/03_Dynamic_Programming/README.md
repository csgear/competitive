## CSES Problem Set - Dynamic Programming

| Problem                                                                  | Type             | Key Technique                | Complexity |
| ------------------------------------------------------------------------ | ---------------- | ---------------------------- | ---------- |
| [1633 - Dice Combinations](1633_dice_combinations.cpp)                   | Basic DP         | Linear recurrence            | O(n)       |
| [1634 - Minimizing Coins](1634_minimizing_coins.cpp)                     | Coin DP          | Unbounded knapsack           | O(n×x)     |
| [1635 - Coin Combinations I](1635_coin_combinations_1.cpp)               | Coin DP          | Combinations with repetition | O(n×x)     |
| [1636 - Coin Combinations II](1636_coin_combinations_2.cpp)              | Coin DP          | Ordered combinations         | O(n×x)     |
| [1637 - Removing Digits](1637_removing_digits.cpp)                       | Basic DP         | Digit manipulation           | O(n log n) |
| [1638 - Grid Paths](1638_grid_path_1.cpp)                                | Grid DP          | Path counting                | O(n²)      |
| [1639 - Edit Distance](1639_edit_distance.cpp)                           | String DP        | Levenshtein distance         | O(nm)      |
| [1158 - Book Shop](1158_book_shop.cpp)                                   | Knapsack         | 0/1 knapsack                 | O(n×x)     |
| [1745 - Money Sums](1745_money_sum.cpp)                                  | Subset DP        | Subset sum variants          | O(n×sum)   |
| [1746 - Array Description](1746_array_description.cpp)                   | Constraint DP    | Adjacent constraints         | O(n×m)     |
| [1093 - Two Sets II](1093_two_sets_2.cpp)                                | Combinatorial    | Subset counting              | O(n²)      |
| [1097 - Removal Game](1097_removal_game.cpp)                             | Interval DP      | Game theory                  | O(n²)      |
| [1140 - Projects](1140_projects.cpp)                                     | Scheduling DP    | Weighted job scheduling      | O(n log n) |
| [1145 - Increasing Subsequence](1145_increasing_subsequence.cpp)         | LIS              | Binary search optimization   | O(n log n) |
| [1748 - Increasing Subsequence II](1748_increasing_subsequence_2.cpp)    | LIS Counting     | Coordinate compression       | O(n log n) |
| [1744 - Rectangle Cutting](1744_rectangle_cutting.cpp)                   | Interval DP      | 2D cutting problem           | O(ab(a+b)) |
| [1653 - Elevator Rides](1653_elevator_riders.cpp)                        | Bitmask DP       | Subset optimization          | O(2ⁿ×n)    |
| [2181 - Counting Tilings](2181_counting_tilings.cpp)                     | Bitmask DP       | Domino tiling                | O(n×2ᵐ×2ᵐ) |
| [2220 - Counting Numbers](2220_counting_numbers.cpp)                     | Digit DP         | Range digit counting         | O(log n)   |
| [2413 - Counting Towers](2413_counting_towers.cpp)                       | State DP         | Combinatorial structures     | O(n)       |
| [2417 - Counting Coprime Pairs](2417_counting_coprime_pairs.cpp)         | Number Theory DP | Möbius function              | O(n log n) |
| [3314 - Mountain Range](3314_mountain_range.cpp)                         | Advanced DP      | Monotonic stack + segtree    | O(n log n) |
| [3359 - Minimal Grid Path](3359_minimal_grid_path.cpp)                   | Grid DP          | Path optimization            | O(n²)      |
| [3403 - Longest Common Subsequence](3403_longest_common_subsequence.cpp) | String DP        | LCS variants                 | O(nm)      |

## Algorithm Categories

### Basic DP Patterns

- **Linear DP**: 1633, 1637
- **Grid DP**: 1638, 3359
- **String DP**: 1639, 3403

### Optimization Problems

- **Knapsack Variants**: 1158, 1634, 1635, 1636, 1745
- **Scheduling**: 1140 (weighted job scheduling)
- **Game Theory**: 1097 (minimax)

### Advanced Techniques

- **Digit DP**: 2220 (range digit problems)
- **Bitmask DP**: 1653, 2181 (subset enumeration)
- **Interval DP**: 1744, 1097 (range optimization)
- **LIS Optimization**: 1145, 1748 (binary search + DP)

### Complex DP

- **State Machine DP**: 2413 (tower building)
- **DP + Data Structures**: 3314 (monotonic stack + segment tree)
- **Number Theory DP**: 2417 (Möbius function)

## Detailed Problem Explanations

### 1140 - Projects (Weighted Job Scheduling)

**Problem Type**: Scheduling DP with binary search optimization

Given n projects with start time, end time, and reward, find maximum reward for non-overlapping projects.

**Key Insight**: Sort by end time, use binary search to find latest non-overlapping project.

**Algorithm**:

```cpp
sort(projects, projects + n); // by end time
dp[0] = projects[0].reward;

for (int i = 1; i < n; i++) {
    ll skip = dp[i - 1];
    ll take = projects[i].reward;

    // Find latest project that doesn't overlap
    auto it = upper_bound(projects, projects + i, projects[i].start,
                          [](int start_time, const Project& p) {
                              return start_time <= p.end;
                          });

    int latest = (it == projects) ? -1 : (it - projects - 1);
    if (latest != -1) {
        take += dp[latest];
    }

    dp[i] = max(skip, take);
}
```

**Complexity**: O(n log n)

### 3314 - Mountain Range

**Problem Type**: Advanced DP with monotonic stack and segment tree

Find maximum mountains you can visit by hang gliding with dominance constraints.

**Key Insight**: Use monotonic stack to find reachable ranges, process by height order.

**Algorithm Components**:

1. **Monotonic Stack**: Find L[i], R[i] (nearest greater elements)
2. **Height Processing**: Process mountains in increasing height order
3. **Segment Tree**: Range maximum queries for DP transitions

**DP Formula**: `dp[i] = 1 + max(dp[L[i]+1], ..., dp[R[i]-1])`

**Why Height Order**: Ensures all reachable mountains are processed before current mountain.

**Complexity**: O(n log n)

### 2220 - Counting Numbers (Digit DP)

**Problem Type**: Digit DP for range queries

Count numbers in range [a, b] with no adjacent equal digits.

**State**: `dp[pos][lastDigit][tight][started]`

- `pos`: Current digit position
- `lastDigit`: Previous digit (for adjacency check)
- `tight`: Whether we're bounded by upper limit
- `started`: Whether we've placed first non-zero digit

**Implementation Pattern**:

```cpp
ll dfs(int pos, int last, bool tight, bool started) {
    if (pos == digits.size()) return started;
    if (!tight && started && memo[pos][last] != -1)
        return memo[pos][last];

    int limit = tight ? digits[pos] : 9;
    ll result = 0;

    for (int digit = 0; digit <= limit; digit++) {
        if (started && digit == last) continue; // adjacent check

        result += dfs(pos + 1, digit,
                     tight && (digit == limit),
                     started || (digit > 0));
    }

    if (!tight && started) memo[pos][last] = result;
    return result;
}
```

### 2413 - Counting Towers

**Problem Type**: State-based DP

Count ways to build towers with structural constraints.

**State Definition**:

- `dp[i][0]`: Ways ending with one merged 2×1 block
- `dp[i][1]`: Ways ending with two separate 1×1 blocks

**Transitions**:

```cpp
dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]) % MOD
dp[i][1] = (dp[i-1][0] + 4 * dp[i-1][1]) % MOD
```

**Base Case**: `dp[1][0] = dp[1][1] = 1`

**Base Case**: `dp[1][0] = dp[1][1] = 1`

### 1745 - Money Sums

**Problem Type**: Subset sum DP

Find all possible sums using given coins.

**Algorithm**: Standard subset sum with reconstruction
**Space Optimization**: Can use bitset for boolean DP

### 1653 - Elevator Rides

**Problem Type**: Bitmask DP

Minimum elevator rides for given people with weight constraints.

**State**: `dp[mask]` = {min_rides, current_weight}
**Transition**: Try adding each person to current ride or start new ride

### Implementation Patterns

### Segment Tree Template (for DP optimization)

```cpp
const int MAXN = 2e5 + 5;
int tree[MAXN << 2];

void push_up(int p) {
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

void update(int p, int pl, int pr, int pos, int val) {
    if (pl == pr) {
        tree[p] = max(tree[p], val);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid) update(p << 1, pl, mid, pos, val);
    else update(p << 1 | 1, mid + 1, pr, pos, val);
    push_up(p);
}

int query(int p, int pl, int pr, int l, int r) {
    if (l > r) return 0;
    if (l <= pl && pr <= r) return tree[p];
    int mid = (pl + pr) >> 1;
    int res = 0;
    if (l <= mid) res = max(res, query(p << 1, pl, mid, l, r));
    if (r > mid) res = max(res, query(p << 1 | 1, mid + 1, pr, l, r));
    return res;
}
```

### Monotonic Stack for Range Problems

```cpp
// Find nearest greater element on left and right
vector<int> L(n, -1), R(n, n);

stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && h[st.top()] <= h[i]) {
        st.pop();
    }
    if (!st.empty()) L[i] = st.top();
    st.push(i);
}

while (!st.empty()) st.pop();

for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && h[st.top()] <= h[i]) {
        st.pop();
    }
    if (!st.empty()) R[i] = st.top();
    st.push(i);
}
```

### Digit DP Template

```cpp
string num;
int dp[20][10][2][2]; // pos, lastDigit, tight, started

int solve(int pos, int last, bool tight, bool started) {
    if (pos == num.size()) return started;
    if (dp[pos][last][tight][started] != -1)
        return dp[pos][last][tight][started];

    int limit = tight ? (num[pos] - '0') : 9;
    int result = 0;

    for (int digit = 0; digit <= limit; digit++) {
        if (started && digit == last) continue; // constraint

        result += solve(pos + 1, digit,
                       tight && (digit == limit),
                       started || (digit > 0));
    }

    return dp[pos][last][tight][started] = result;
}
```

## Complexity Analysis

| Technique            | Typical Complexity | When to Use                    |
| -------------------- | ------------------ | ------------------------------ |
| Basic DP             | O(n), O(n²)        | Simple recurrence relations    |
| Knapsack             | O(n×W)             | Weight/capacity constraints    |
| LIS + Binary Search  | O(n log n)         | Sequence optimization          |
| Digit DP             | O(d×10×states)     | Range digit problems           |
| Bitmask DP           | O(2ⁿ×n)            | Small subset problems (n ≤ 20) |
| Interval DP          | O(n³)              | Range-based problems           |
| DP + Segment Tree    | O(n log n)         | Range queries in DP            |
| DP + Monotonic Stack | O(n)               | Nearest greater/smaller        |

## Common Optimization Techniques

1. **Space Optimization**: Rolling arrays for 1D/2D DP
2. **Binary Search**: For LIS, scheduling problems
3. **Data Structures**: Segment tree, BIT for range operations
4. **Coordinate Compression**: For large value ranges
5. **Memoization**: Top-down DP with caching
6. **State Reduction**: Minimize DP dimensions
