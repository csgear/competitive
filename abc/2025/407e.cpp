// https://atcoder.jp/contests/abc407/tasks/abc407_e

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        priority_queue<long long> q;
        long long x;
        cin >> x;
        long long ans = x;
        cin >> x;
        q.push(x);
        for (int i = 1; i < N; i++) {
            cin >> x;
            q.push(x);
            ans += q.top();
            q.pop();
            cin >> x;
            q.push(x);
        }
        cout << ans << endl;
    }
    return 0;
}
