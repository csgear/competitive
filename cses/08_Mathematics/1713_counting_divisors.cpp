// https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int cnt[N + 1];

int main() {
    int n;
    cin >> n;

    for (int g = 1; g <= N; g++) {
        for (int multiple = g; multiple <= N; multiple += g) {
            cnt[multiple]++;
        }
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << cnt[x] << endl;
    }
    return 0;
}
