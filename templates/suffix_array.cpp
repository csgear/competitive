// Suffix Array Implementation
// Based on radix sort with doubling technique
// Time Complexity: O(n log n), Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

// Global arrays for suffix array construction
char s[MAXN];     // Input string (1-indexed)
int n;            // Length of string
int sa[MAXN];     // Suffix array: sa[i] = starting position of i-th smallest suffix
int rk[MAXN];     // Rank array: rk[i] = rank of suffix starting at position i
int oldrk[MAXN];  // Previous iteration's rank array
int id[MAXN];     // Temporary array for sorting by second key
int px[MAXN];     // Stores first key (rank) for each suffix during radix sort
int cnt[MAXN];    // Counting sort array

// Compare function: checks if two suffixes have same rank for length 2*w
// x, y: starting positions of suffixes to compare
// w: current window size (we compare first 2*w characters)
bool cmp(int x, int y, int w) { return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]; }

int main() {
    int i, m = 300, p, w;  // m = max character value, p = number of distinct ranks, w = window size

    // Read input string (1-indexed for easier implementation)
    scanf("%s", s + 1);
    n = strlen(s + 1);

    // === INITIAL SORTING: Sort suffixes by first character ===
    // Count frequency of each character
    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];

    // Convert counts to positions (cumulative sum)
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];

    // Build initial suffix array using counting sort
    // Process from right to left to maintain stability
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

    // === DOUBLING PHASE: Iteratively sort by longer prefixes ===
    // In each iteration, we sort suffixes by their first 2*w characters
    // using the ranks from previous iteration (first w characters)
    for (w = 1; w < n; w <<= 1, m = p) {  // w doubles each iteration, m=p optimizes counting range

        // === STEP 1: Sort by second key (characters at positions w to 2w-1) ===
        // First, handle suffixes that don't have a second part (length < w)
        // These suffixes should come first (empty second key = smallest)
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;

        // Then, for suffixes with second part, use their current ranking
        // sa[i] > w means suffix sa[i] has enough characters for second key
        // The second key of suffix sa[i] is the rank of suffix sa[i] - w
        for (i = 1; i <= n; ++i)
            if (sa[i] > w) id[++p] = sa[i] - w;

        // === STEP 2: Sort by first key (characters at positions 0 to w-1) ===
        // Reset counting array for radix sort
        memset(cnt, 0, sizeof(cnt));

        // Count frequency of each rank (first key)
        for (i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];

        // Convert counts to positions
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];

        // Build new suffix array using counting sort on first key
        // id[i] contains suffixes sorted by second key
        // We sort them by first key while maintaining second key order
        for (i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];

        // === STEP 3: Update ranks for next iteration ===
        // Save current ranks before updating
        memcpy(oldrk, rk, sizeof(rk));

        // Assign new ranks: suffixes with same 2*w prefix get same rank
        for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;

        // If all suffixes have different ranks, we're done
        // (p == n means all suffixes are uniquely sorted)
    }

    // Output the suffix array: positions of suffixes in sorted order
    for (i = 1; i <= n; ++i) printf("%d ", sa[i]);

    return 0;
}
