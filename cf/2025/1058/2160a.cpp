// https://codeforces.com/contest/2160/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (int i = 0; i <= 100; i++) {
            if (cnt[i] == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}