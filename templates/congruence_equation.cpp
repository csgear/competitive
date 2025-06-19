// https://www.luogu.com.cn/problem/P1082
// P1082 同余方程

#include <bits/stdc++.h>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long x, y;
    extended_gcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
}
