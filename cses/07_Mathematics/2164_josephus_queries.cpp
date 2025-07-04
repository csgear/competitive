// https://cses.fi/problemset/task/2164

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int find_kth_removed(int n, int k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (2 * k > n)
            return 2 * k % n;
        else
            return 2 * k;
    }

    int c = find_kth_removed(n >> 1, k - (n + 1) / 2);
    if (n & 1)
        return 2 * c + 1;
    else
        return 2 * c - 1;
}

int main() {
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll n, k;
        cin >> n >> k;
        cout << find_kth_removed(n, k) << endl;
    }
    return 0;
}