// https://www.acwing.com/problem/content/1089/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, k;
ll s[N];
// f[0] = 0 because no elements means sum is 0
ll f[N], q[N];

ll g(int i) { return f[max(0, i - 1)] - s[i]; }

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int l = 1, r = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && q[l] < i - k) {
            l++;
        }
        f[i] = max(f[i - 1], g(q[l]) + s[i]);
        while (l <= r && g(q[r]) <= g(i)) {
            r--;
        }
        q[++r] = i;
    }
    cout << f[n] << endl;
    return 0;
}