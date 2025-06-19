// Cow Tipping【USACO 2017 January Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10 + 5;

int n;

int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    int count = 0;
    for (int x = n - 1; x >= 0; --x) {
        for (int y = n - 1; y >= 0; --y) {
            if (a[x][y] == 1) {
                ++count;
                for (int i = 0; i <= x; ++i) {
                    for (int j = 0; j <= y; ++j) {
                        a[i][j] = 1 - a[i][j];
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
