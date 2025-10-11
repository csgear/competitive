// https://www.acwing.com/problem/content/203/

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int phi[N], primes[N], cnt;
bool st[N];
int pre[N];

void euler1(int n) {
    for (int i = 2; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                // φ(p^k) = p^(k-1)×(p-1)
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void euler2(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

void init() {
    euler1(1000);
    cout << "i phi(i)" << endl;
    for (int i = 1; i <= 20; i++) {
        cout << i << " " << phi[i] << endl;
    }
    euler2(1000);
    cout << "i phi(i)" << endl;
    for (int i = 1; i <= 20; i++) {
        cout << i << " " << phi[i] << endl;
    }
    for (int i = 1; i <= 1000; i++) {
        pre[i] = pre[i - 1] + phi[i];
    }
}

int main() {
    int c, n;
    cin >> c;
    init();
    for (int i = 1; i <= c; i++) {
        cin >> n;
        cout << i << " " << n << " " << pre[n] * 2 + 3 << endl;
    }
    return 0;
}