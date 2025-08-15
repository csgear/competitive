// https://cses.fi/problemset/task/3304

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 20;

int n, q;
int h[MAXN];
int nxt[MAXN];
int up[MAXN][LOG];
int cnt[MAXN][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> h[i];

    // 1. 单调栈找右边第一个更高的建筑
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (st.empty())
            nxt[i] = n + 1;  // 没有更高的
        else
            nxt[i] = st.top();
        st.push(i);
    }

    // 2. 初始化倍增表
    for (int i = 1; i <= n; i++) {
        up[i][0] = nxt[i];
        cnt[i][0] = (nxt[i] <= n ? 1 : 0);
    }
    up[n + 1][0] = n + 1;
    cnt[n + 1][0] = 0;

    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n + 1; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
            cnt[i][k] = cnt[i][k - 1] + cnt[up[i][k - 1]][k - 1];
        }
    }

    // 3. 处理查询
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;  // 起点建筑可见
        int cur = l;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[cur][k] <= r) {
                ans += cnt[cur][k];
                cur = up[cur][k];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
