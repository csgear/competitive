## CSES Problem Set - Sorting and Searching

### 1621 Distinct Numbers

Sorting, the left to right swiping (n _ log n)
Use set, and check the set size (n _ log n on insertion)

### 1084 Apartments

Sort apartments and desires, then use greedy approach,

Gives each applicant the smallest apartment that satisfies the wish (if there is such an apartment available).

### 1090 Ferris Wheel

each step places the heaviest child in a gondola. If the lightest child can also placed in the same gondola, this is done and the gondola will have two children. Otherwise the heaviest child will be alone in the gondola.

### 1091 Concert Tickets

We need a data structure (a sorted tree) to simulate the process (specially the erase operation)

Also, we handle the customer's requrest in order. It's not looking for a global optimal solution.

### 1619 Restaurant Customers

Assume that all arrival and leaving times are distinct. We can use event queue to keep track of the number of customers and maintain the highest number. {+1, -1} trick can be played.

### 1629 Moive Festival

Like task scheduling problem with interval. Always pick the movie which ends early to watch more movies

### 1640 Sum of Two Values

You can use either sorting or map to find a + b = x,

We can solve it by 2-points after sorting. (Not it's not sliding window)

### 1643 Maximum Subarray Sum

Kadane's Algorithm

### 1074 Stick Length

Find median (sorting O(n \* log n)) or selection O(n)

### 2182 Missing Coin Sum

Suppose that we can create all sums 1,2, ..., k using a subset of coins. Then we add coin new coin with vaule x, can we get k+1?

### 2216 Collecting Numbers

It's a tricky implementation. If x is before x-1, we increase round by 1

### 2217 Collection Numbers II

Only think about local

### 1141 Playlist

Find the max size of a sliding window containing unique songs

### 1073 Towers

Greedy approach: for each cube, find the smallest tower top that is >= current cube. If no such tower exists, create a new tower. Use multiset for efficient operations.

### 3420 Distinct Value Subarrays

Count subarrays where all elements are distinct. Use sliding window with two pointers and hashmap to track last position of each element. When duplicate found, move left pointer.

### 3421 Distinct Value Subsequences

Count subsequences where all elements are distinct. Use combinatorial approach: for each distinct element with frequency f, we have (f+1) choices (don't include or include once). Multiply all choices and subtract 1 for empty subsequence.

### 1660 Subarray Sum I

for all positive numbers, use sliding window to find the nunber of subarrays

### 1661 Subarray Sum II

if the array contains negative numbers, sliding window doesn't work out.

Convert the sum from [i, j] to be prefix_sum[j] - prefix_sum[i-1], then use map
