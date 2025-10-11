
// https://www.acwing.com/problem/content/1294/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

bool prime[MAXN];
bool vis[MAXN];

void linearSieve() {
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) prime[i] = true;
        for (int j = 2; j <= MAXN / i; j++) {
            vis[i * j] = true;
            if (i % j == 0) break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(nullptr);

    linearSieve();

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 3; i <= n / 2; i += 2) {
            if (prime[i] && prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
        }
    }
    return 0;
}