// https://www.acwing.com/problem/content/99/

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int MOD = 9901;

unordered_map<int, int> mp;

void divide(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            mp[i] += cnt;
        }
    }
    if (x > 1) mp[x]++;
}

int modmul(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % MOD;
        a = (LL)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int A, B;
    cin >> A >> B;
    divide(A);
    cout << mp.size() << endl;
    int res = 1;
    for (auto [p, k] : mp) {
        if ((p - 1) % MOD == 0) {
            res = (LL)res * (k * B + 1) % MOD;

        } else {
            res = (LL)res * (modmul(p, k * B + 1) - 1 + MOD) % MOD * modmul(p - 1, MOD - 2) % MOD;
        }
    }
    if (!A) res = 0;
    cout << res << endl;
    return 0;
}