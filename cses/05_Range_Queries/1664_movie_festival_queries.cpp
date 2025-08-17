// https://cses.fi/problemset/task/1664

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5, M = 1e6, LOG = 20;
const int INF = 1e9 + 5;

int n, q, jump[M + 6][LOG];
vector<pair<int, int>> movies;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    movies.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end());
    memset(jump, -1, sizeof(jump));

    for (int i = M, j = INF; i >= 1; --i) {
        while (!movies.empty() && movies.back().first >= i) {
            j = min(j, movies.back().second);
            movies.pop_back();
        }
        jump[i][0] = j;
    }
    for (int k = 1; (1 << k) <= M; ++k) {
        for (int i = 1; i <= M; ++i) {
            if (jump[i][k - 1] != -1 && jump[i][k - 1] <= M) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }
    }
    while (q--) {
        int a, b, ans = 0;
        cin >> a >> b;
        for (int k = LOG - 1; k >= 0; --k) {
            if (jump[a][k] != -1 && jump[a][k] <= b) {
                a = jump[a][k];
                ans += (1 << k);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
