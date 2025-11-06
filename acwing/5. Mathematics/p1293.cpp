// https://www.acwing.com/problem/content/1295/
// 1293. 夏洛克和他的女朋友

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int primes[N], cnt = 0;
bool st[N];
int n;

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    cin >> n;

    get_primes(n + 1);

    if (n <= 2) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    for (int i = 2; i <= n + 1; i++) {
        if (st[i])
            cout << 2 << " ";
        else
            cout << 1 << " ";
    }
    return 0;
}