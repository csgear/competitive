// https://www.luogu.com.cn/problem/P3152

#include <bits/stdc++.h>
using namespace std;

int f(int n) { return n == 1 ? 1 : f(n / 2) + 1; }

int main() {
    int n;
    cin >> n;
    int ans = f(n);
    cout << ans << endl;
    return 0;
}