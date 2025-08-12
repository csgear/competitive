// https://cses.fi/problemset/task/1096
// Throwing Dice - Matrix Exponentiation for Linear Recurrence

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    vector<vector<ll>> C(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> base, ll exp) {
    int n = base.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));

    // Initialize result as identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    while (exp > 0) {
        if (exp & 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    // Transition matrix for the recurrence relation:
    // f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
    // State vector: [f(n-5), f(n-4), f(n-3), f(n-2), f(n-1), f(n)]
    vector<vector<ll>> transition(6, vector<ll>(6, 0));

    // Shift previous values
    for (int i = 0; i < 5; i++) {
        transition[i][i + 1] = 1;
    }

    // f(n) = sum of all previous 6 values
    for (int i = 0; i < 6; i++) {
        transition[5][i] = 1;
    }

    if (n <= 6) {
        // Base cases: f(0)=1, f(1)=1, f(2)=2, f(3)=4, f(4)=8, f(5)=16, f(6)=32
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * 2) % MOD;
        }
        cout << ans << '\n';
    } else {
        // Use matrix exponentiation for n > 6
        vector<vector<ll>> result = matrix_power(transition, n - 6);

        // Initial state: [f(0), f(1), f(2), f(3), f(4), f(5)] = [1, 1, 2, 4, 8, 16]
        vector<ll> initial = {1, 1, 2, 4, 8, 16};

        ll ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + result[5][i] * initial[i]) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}