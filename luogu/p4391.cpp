// https://www.luogu.com.cn/problem/P4391
// P4391 [BalticOI 2009] Radio Transmission 无线传输

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
string s;
int nxt[MAXN];

int main() {
    int n;
    cin >> n >> s;
    nxt[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = nxt[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }
    cout << n - (nxt[n - 1] + 1) << endl;
    return 0;
}