// https://www.luogu.com.cn/problem/P1090

#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long

int n, ans;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    fastio;

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