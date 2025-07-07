// https://cses.fi/problemset/task/1631

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    ll max_book = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        max_book = max(max_book, a);
    }
    cout << max(max_book * 2, sum) << endl;
    return 0;
}