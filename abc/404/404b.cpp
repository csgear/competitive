// https://atcoder.jp/contests/abc404/tasks/abc404_b

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
char S[MAXN][MAXN], T[MAXN][MAXN], tmp[MAXN][MAXN];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%s", S[i] + 1);
    for (int i = 1; i <= n; i++) scanf("%s", T[i] + 1);
    int ans = 1e9;
    for (int rotation = 0; rotation < 4; rotation++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cnt += (S[i][j] != T[i][j]);
            }
        }
        ans = min(ans, cnt + rotation);
        // rotate T, clockwise 90 degrees
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                tmp[j][n - i + 1] = S[i][j];
            }
        }
        // copy tmp to T
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                S[i][j] = tmp[i][j];
            }
        }
    }

    cout << ans << endl;
    return 0;
}