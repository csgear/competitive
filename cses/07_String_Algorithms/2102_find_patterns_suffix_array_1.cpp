// https://cses.fi/problemset/task/2102
// Find Patterns - Solution using Suffix Array

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

char s[MAXN];
int n;
int sa[MAXN], rk[MAXN], oldrk[MAXN], id[MAXN], px[MAXN], cnt[MAXN];

bool cmp(int x, int y, int w) { return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]; }

void build_suffix_array() {
    int i, m = 300, p, w;

    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

    for (w = 1; w < n; w <<= 1, m = p) {
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (i = 1; i <= n; ++i)
            if (sa[i] > w) id[++p] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[px[i]]--] = id[i];

        memcpy(oldrk, rk, sizeof(rk));
        for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
}

bool find_pattern(const string& pattern) {
    int m = pattern.length();
    int left = 1, right = n;

    while (left <= right) {
        int mid = (left + right) / 2;
        int pos = sa[mid];

        int cmp_result = 0;
        for (int i = 0; i < m && pos + i <= n; ++i) {
            if (pattern[i] < s[pos + i]) {
                cmp_result = -1;
                break;
            } else if (pattern[i] > s[pos + i]) {
                cmp_result = 1;
                break;
            }
        }

        if (cmp_result == 0 && pos + m - 1 < n) {
            return true;
        }

        if (cmp_result <= 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    strcpy(s + 1, input.c_str());
    strcat(s + 1, "$");
    n = strlen(s + 1);

    build_suffix_array();

    int k;
    cin >> k;
    for (int ki = 1; ki <= k; ki++) {
        string p;
        cin >> p;
        cout << (find_pattern(p) ? "YES" : "NO") << "\n";
    }

    return 0;
}
