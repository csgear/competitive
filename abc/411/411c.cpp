// https://atcoder.jp/contests/abc411/tasks/abc411_c

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int a[MAXN];

int n, q;

int main() {
    cin >> n >> q;
    int cnt = 0;

    // a[0] = a[n+1] = 0
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        a[x] ^= 1;

        // if left and right are not 1
        if ((a[x - 1] != 1) && a[x + 1] != 1) {
            if (a[x] == 1)
                cnt++;
            else
                cnt--;
        } else if (a[x - 1] == 1 && a[x + 1] == 1) {
            if (a[x] == 1)
                cnt--;
            else
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}