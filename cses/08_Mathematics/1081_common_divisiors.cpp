// https://cses.fi/problemset/task/1081

#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int cnt[N + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int gcd = N; gcd >= 1; gcd--) {
        int count = 0;

        for (int multiple = gcd; multiple <= N; multiple += gcd) {
            count += cnt[multiple];
        }

        if (count >= 2) {
            cout << gcd << endl;
            return 0;
        }
    }

    return 0;
}