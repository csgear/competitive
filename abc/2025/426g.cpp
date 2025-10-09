// https://atcoder.jp/contests/abc426/tasks/abc426_g

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int K = 510;
const int N = 2e4 + 10;
const int M = 2e5 + 10;

int w[N], v[N];
ll dp[N][K];
tuple<int, int, int> query[M];
vector<ll> ans;

void knapsack_transition(int pre_idx, int nx_idx, int i) {
    for (int j = 0; j < K; j++) {
        dp[nx_idx][j] = dp[pre_idx][j];
        if (j >= w[i]) {
            dp[nx_idx][j] = max(dp[nx_idx][j], dp[pre_idx][j - w[i]] + v[i]);
        }
    }
}

void solve(int l, int r, const vector<int> &qid) {
    if (l + 1 == r) {
        for (int i : qid) {
            auto [nl, nr, nc] = query[i];
            // assert(nl == l && nr == r);
            ans[i] = (nc >= w[l] ? v[l] : 0);
        }
        return;
    }
    int m = (l + r) / 2;
    memset(dp[m], 0, sizeof(dp[m]));
    for (int i = m - 1; i >= l; i--) knapsack_transition(i + 1, i, i);
    for (int i = m + 1; i <= r; i++) knapsack_transition(i - 1, i, i - 1);
    vector<int> qid_l, qid_r;
    for (int i : qid) {
        auto [nl, nr, nc] = query[i];
        if (nr <= m) {
            qid_l.push_back(i);
        } else if (nl >= m) {
            qid_r.push_back(i);
        } else {
            for (int j = 0; j <= nc; j++) {
                ans[i] = max(ans[i], dp[nl][j] + dp[nr][nc - j]);
            }
        }
    }
    solve(l, m, qid_l);
    solve(m, r, qid_r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        --l;
        query[i] = make_tuple(l, r, c);
    }
    ans.resize(q, 0);
    memset(dp, 0, sizeof(dp));
    vector<int> qid(q);
    iota(qid.begin(), qid.end(), 0);
    solve(0, n, qid);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}