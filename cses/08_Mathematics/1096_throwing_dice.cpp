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

    vector<vector<ll>> matrix(6, vector<ll>(6, 0));

    // Shift previous values
    for (int i = 0; i < 5; i++) {
        matrix[i][i + 1] = 1;
    }

    // f(n) = sum of all previous 6 values
    for (int i = 0; i < 6; i++) {
        matrix[5][i] = 1;
    }

    vector<ll> initial = {1, 2, 4, 8, 16, 32};

    if (n <= 6) {
        cout << initial[n - 1] << '\n';
    } else {
        vector<vector<ll>> result = matrix_power(matrix, n - 6);

        ll ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = (ans + result[5][i] * initial[i]) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}