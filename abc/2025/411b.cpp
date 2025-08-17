// https://atcoder.jp/contests/abc411/tasks/abc411_b

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;
int d[MAXN];

int main() {
    int n;
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int s = 0;
        for (int j = i + 1; j <= n; j++) {
            s += d[j];
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}