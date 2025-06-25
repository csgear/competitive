// https://www.luogu.com.cn/problem/P1031

#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int avg = s / n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // If the current element is not equal to the average,
        // there is a need of one adjustment
        if (a[i] != avg) {
            a[i + 1] += a[i] - avg;
            ans++;
        }
    }
    // 从第二个元素开始，如果当前元素和平均值的差值不为0，则需要进行一次调整
    // for (int i = 1; i <= n; i++) {
    //     s += a[i];
    //     if (s != a[i] * avg) {
    //         ans++;
    //     }
    // }
    cout << ans << endl;
    return 0;
}