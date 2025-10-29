// https://www.luogu.com.cn/problem/P1090
// greedy algorithm to minimize the cost of merging fruit piles

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;

    // min-heap
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        q.push(t);
    }

    while (q.size() > 1) {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    cout << ans << endl;
    return 0;
}