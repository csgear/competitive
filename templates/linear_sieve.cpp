// https://www.luogu.com.cn/problem/P3383
// P3383 【模板】线性筛素数

#include <bits/stdc++.h>
using namespace std;

vector<int> linearSieve(int n) {
    vector<int> primes;
    vector<bool> vis(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return primes;
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> primes = linear_sieve(n);
    while (q--) {
        int x;
        cin >> x;
        cout << primes[x - 1] << "\n";
    }
}
