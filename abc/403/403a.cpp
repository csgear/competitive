// https://atcoder.jp/contests/abc403/tasks/abc403_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int d;
    for (int i = 1; i <= n; i++) {
        cin >> d;
        if (i % 2 == 1) {
            sum += d;
        }
    }
    cout << sum << endl;
}
