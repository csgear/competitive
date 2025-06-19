// https://atcoder.jp/contests/abc391/tasks/abc391_d

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, w;

pair<pair<int, int>, int> box[MAXN];
pair<pair<int, int>, int> qry[MAXN];

deque<int> dq[MAXN];
int cnt;
int alive[MAXN];
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int X, Y;
        cin >> X >> Y;
        box[i] = {{Y, X}, i};
        alive[i] = 1;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int T, A;
        cin >> T >> A;
        qry[i] = {{T, A}, i};
    }
    sort(box + 1, box + n + 1);
    sort(qry + 1, qry + q + 1);

    int ps = 1;

    for (int i = 1; i <= q; i++) {
        auto [T, A] = qry[i].first;
        int idx = qry[i].second;
        while (ps <= n && box[ps].first.first <= T) {
            if (dq[box[ps].first.second].empty()) {
                ++cnt;
            }
            dq[box[ps].first.second].push_back(box[ps].second);
            ps++;
        }
        while (cnt == w) {
            for (int j = 1; j <= w; j++) {
                alive[dq[j].front()] = 0;
                dq[j].pop_front();
                if (dq[j].empty()) {
                    --cnt;
                }
            }
        }
        ans[idx] = alive[A];
    }

    for (int i = 1; i <= q; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}