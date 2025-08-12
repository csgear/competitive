
// https://cses.fi/problemset/task/1723

// Graph Paths I - Matrix Exponentiation

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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> adj(n, vector<ll>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;  // Convert to 0-indexed
        adj[a][b]++;
    }

    vector<vector<ll>> result = matrix_power(adj, k);

    cout << result[0][n - 1] << '\n';

    return 0;
}