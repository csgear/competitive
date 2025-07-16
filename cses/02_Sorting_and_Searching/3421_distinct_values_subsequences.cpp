// https://cses.fi/problemset/task/3421

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    long long res = 1;
    for (auto [v, c] : freq) {
        res = res * (c + 1) % MOD;
    }

    cout << res - 1 << endl;
    return 0;
}