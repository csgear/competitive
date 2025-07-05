// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int i = 1, j = n;
    while (i < j) {
        if (a[i].first + a[j].first == x) {
            cout << a[i].second << " " << a[j].second << endl;
            return 0;
        }
        if (a[i].first + a[j].first < x) {
            i++;
        } else {
            j--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}