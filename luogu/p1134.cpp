// https://www.luogu.com.cn/problem/P1134
// P1134 [USACO3.2] 阶乘问题

#include <iostream>
using namespace std;

int pow2mod10(int n) {
    // 2^n mod 10 cycles every 4: 2,4,8,6
    int cycle[] = {6, 2, 4, 8};
    if (n == 0) return 1;
    return cycle[n % 4];
}

int last_digit(int n) {
    if (n == 0) return 1;
    int d[] = {1, 1, 2, 6, 4};
    int res = last_digit(n / 5) * d[n % 5] % 10;
    res = res * pow2mod10(n / 5) % 10;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << last_digit(n) << endl;
    return 0;
}