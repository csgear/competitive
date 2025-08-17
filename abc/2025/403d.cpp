// https://atcoder.jp/contests/abc403/tasks/abc403_d

#include <bits/stdc++.h>
using namespace std;

int n, d;
int cnt[1000005];
int dp[1000005][2];

int solve(vector<int> &v) {
    if (v.size() == 0) return 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        dp[i + 1][0] = max(dp[i][0], dp[i][1]);
        dp[i + 1][1] = dp[i][0] + v[i];
        sum += v[i];
    }
    return sum - max(dp[v.size()][0], dp[v.size()][1]);
}

int main() {
    cin >> n >> d;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;

    if (d == 0) {
        for (int i = 0; i <= 1000000; i++) {
            ans += max(0, cnt[i] - 1);
        }
    } else {
        for (int i = 0; i < d; i++) {
            vector<int> v;
            for (int j = i; j < 1000005; j += d) {
                if (cnt[j] > 0) {
                    v.push_back(cnt[j]);
                } else {
                    ans += solve(v);
                    v.clear();
                }
            }
            ans += solve(v);
        }
    }

    cout << ans << endl;

    return 0;
}