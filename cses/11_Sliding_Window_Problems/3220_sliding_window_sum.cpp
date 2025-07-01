// https://cses.fi/problemset/task/3220

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    long long sum = 0, ans = 0;
    queue<long long> q;
    for (int i = 0; i < k; i++) {
        sum += x;
        q.push(x);
        x = (x * a + b) % c;
    }
    ans = sum;
    for (int i = k; i < n; i++) {
        sum -= q.front();
        q.pop();
        sum += x;
        q.push(x);
        ans = ans ^ sum;
        x = (x * a + b) % c;
    }
    cout << ans << endl;
    return 0;
}