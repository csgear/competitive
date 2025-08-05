// https://cses.fi/problemset/task/3314

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int tree[MAXN << 2];

void push_up(int p) { tree[p] = max(tree[p << 1], tree[p << 1 | 1]); }

void update(int p, int pl, int pr, int pos, int val) {
    if (pl == pr) {
        tree[p] = max(tree[p], val);
        return;
    }
    int mid = (pl + pr) >> 1;
    if (pos <= mid)
        update(p << 1, pl, mid, pos, val);
    else
        update(p << 1 | 1, mid + 1, pr, pos, val);
    push_up(p);
}

int query(int p, int pl, int pr, int l, int r) {
    if (l > r) return 0;
    if (l <= pl && pr <= r) {
        return tree[p];
    }
    int mid = (pl + pr) >> 1;
    int res = 0;
    if (l <= mid) res = max(res, query(p << 1, pl, mid, l, r));
    if (r > mid) res = max(res, query(p << 1 | 1, mid + 1, pr, l, r));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> L(n, -1), R(n, n);

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }
        if (!st.empty()) {
            L[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) {
            st.pop();
        }
        if (!st.empty()) {
            R[i] = st.top();
        }
        st.push(i);
    }

    vector<pair<int, int>> mountains;  // {height, index}
    for (int i = 0; i < n; i++) {
        mountains.push_back({h[i], i});
    }
    sort(mountains.begin(), mountains.end());

    vector<int> dp(n, 1);

    // Process mountains in increasing order of height
    for (int idx = 0; idx < n;) {
        int currentHeight = mountains[idx].first;
        vector<int> sameHeight;

        while (idx < n && mountains[idx].first == currentHeight) {
            sameHeight.push_back(mountains[idx].second);
            idx++;
        }

        for (int i : sameHeight) {
            int left = L[i] + 1;
            int right = R[i] - 1;

            if (left <= right) {
                dp[i] = 1 + query(1, 0, n - 1, left, right);
            }
        }

        // we need to update the segment tree with new DP values once
        // we are done processing all mountains of the same height
        for (int i : sameHeight) {
            update(1, 0, n - 1, i, dp[i]);
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result << "\n";

    return 0;
}