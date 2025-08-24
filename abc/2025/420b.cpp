// https://atcoder.jp/contests/abc420/tasks/abc420_b

#include <bits/stdc++.h>

using namespace std;

int points[105];
char s[105][105];

int main() {
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        points[i] = 0;
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i][j] == '0')
                cnt0++;
            else
                cnt1++;
        }
        if (cnt0 == 0 || cnt1 == 0) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt0 < cnt1 && s[i][j] == '0') {
                points[i]++;
            }
            if (cnt0 > cnt1 && s[i][j] == '1') {
                points[i]++;
            }
        }
    }
    int max_point = *max_element(points + 1, points + n + 1);

    for (int i = 1; i <= n; i++) {
        if (points[i] == max_point) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}