// https://cses.fi/problemset/task/3413

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
char a[N][N];
short h[26][N];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<long long> ans(k, 0);

    // For each row
    for (int i = 1; i <= n; ++i) {
        // For each letter, update heights for this row
        for (int c = 0; c < k; ++c) {
            for (int j = 1; j <= n; ++j) {
                h[c][j] = (a[i][j] == 'A' + c) ? h[c][j] + 1 : 0;
            }
        }

        // For each letter, run the histogram stack algorithm
        for (int c = 0; c < k; ++c) {
            int st_h[N], st_cnt[N], top = 0;
            long long row_sum = 0;
            for (int j = 1; j <= n; ++j) {
                int cnt = 1;
                while (top > 0 && st_h[top - 1] >= h[c][j]) {
                    row_sum -= 1LL * st_h[top - 1] * st_cnt[top - 1];
                    cnt += st_cnt[--top];
                }
                row_sum += 1LL * h[c][j] * cnt;
                st_h[top] = h[c][j];
                st_cnt[top++] = cnt;
                ans[c] += row_sum;
            }
        }
    }

    for (int c = 0; c < k; ++c) {
        cout << ans[c] << '\n';
    }
    return 0;
}