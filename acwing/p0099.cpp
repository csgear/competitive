// https://www.acwing.com/problem/content/101/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5010;
int s[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R;
    cin >> N >> R;

    R = min(R, MAXN - 1);

    while (N--) {
        int x, y, w;
        cin >> x >> y >> w;
        x++;
        y++;
        s[x][y] += w;
    }

    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    }

    int ans = INT_MIN;
    for (int i = R; i < MAXN; i++) {
        for (int j = R; j < MAXN; j++) {
            ans = max(ans, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
        }
    }
    cout << ans << endl;
    return 0;
}