// https://cses.fi/problemset/task/1645

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}