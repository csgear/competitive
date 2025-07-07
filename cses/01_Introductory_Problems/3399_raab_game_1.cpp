// https://cses.fi/problemset/task/3399

#include <bits/stdc++.h>
using namespace std;

void solve(int n, int a, int b) {
    if (a + b > n) {
        cout << "NO" << endl;
        return;
    }

    if (a + b > 0 && (a == 0 || b == 0)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    // player 1
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
    // Player 2
    for (int i = 1; i <= b; i++) {
        cout << a + i << " ";
    }
    for (int i = 1; i <= a; i++) {
        cout << i << " ";
    }

    for (int i = a + b + 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}