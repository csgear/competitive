// https://www.luogu.com.cn/problem/P3375

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
char s1[MAXN], s2[MAXN];
int nxt[MAXN];

// 0-based indexing solution
int main() {
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);

    // Build next array (0-indexed)
    // nxt[i] stores the length of longest proper prefix
    // that's also suffix, minus 1 (because of 0-indexing)
    nxt[0] = -1;
    for (int i = 1, j = -1; i < m; i++) {
        while (j >= 0 && s2[i] != s2[j + 1]) {
            j = nxt[j];
        }
        if (s2[i] == s2[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }

    // KMP matching (0-indexed)
    // j = -1 means "no characters matched"
    // j >= 0 means "j+1 characters matched"
    for (int i = 0, j = -1; i < n; i++) {
        while (j >= 0 && s1[i] != s2[j + 1]) {
            j = nxt[j];
        }
        if (s1[i] == s2[j + 1]) {
            j++;
        }
        if (j == m - 1) {
            cout << i - m + 2 << endl;  // Convert to 1-indexed output
            j = nxt[j];
        }
    }

    // Output next array (convert to 1-indexed)
    for (int i = 0; i < m; i++) {
        cout << nxt[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}