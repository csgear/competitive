// https://www.acwing.com/problem/content/1026/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, V;
    cin >> V >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<int> dp(V + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout << V - dp[V] << endl;
    return 0;
}