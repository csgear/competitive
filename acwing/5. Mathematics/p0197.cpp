// https://www.acwing.com/problem/content/199/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void init(int n) {
    memset(st, 0, sizeof st);
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (st[i] == false) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        int s = 0;
        for (int j = n; j; j /= p) {
            s += j / p;
        }
        cout << p << " " << s << "\n";
    }
    return 0;
}