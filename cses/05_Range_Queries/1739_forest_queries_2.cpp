// https://cses.fi/problemset/task/1739

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1005;

int N, Q;
int nums[MAXN][MAXN];
ll ds[MAXN][MAXN];

int lowbit(int x) { return x & -x; }

void update(int x, int y, ll val) {
    for (int i = x; i <= N; i += lowbit(i))
        for (int j = y; j <= N; j += lowbit(j)) ds[i][j] += val;
}

ll query(int x, int y) {
    ll sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j)) sum += ds[i][j];
    return sum;
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            nums[i][j] = (s[j - 1] == '*') ? 1 : 0;
            if (nums[i][j]) update(i, j, 1);
        }
    }
    for (int q = 0, t, x1, y1, x2, y2; q < Q; q++) {
        cin >> t >> x1 >> y1;
        if (t == 1) {
            if (nums[x1][y1] == 1) {
                update(x1, y1, -1);
                nums[x1][y1] = 0;
            } else if (nums[x1][y1] == 0) {
                update(x1, y1, 1);
                nums[x1][y1] = 1;
            }
        } else if (t == 2) {
            cin >> x2 >> y2;
            cout << query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1)
                 << endl;
        }
    }
}
