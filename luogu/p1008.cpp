// https://www.luogu.com.cn/problem/P1008

#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (i == j || i == k || j == k) continue;
                int a = i * 100 + j * 10 + k;
                int b = 2 * a;
                int c = 3 * a;
                if (c >= 1000) return 0;
                int l = b / 100, m = (b - l * 100) / 10, n = b % 10;
                int o = c / 100, p = (c - o * 100) / 10, q = c % 10;
                if (i + j + k + l + m + n + o + p + q == 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 &&
                    i * j * k * l * m * n * o * p * q == 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)
                    cout << a << " " << b << " " << c << endl;
            }
        }
    }
    return 0;
}