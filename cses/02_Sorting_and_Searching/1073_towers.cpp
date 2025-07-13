// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> towers;
    for (auto &x : a) {
        auto it = upper_bound(towers.begin(), towers.end(), x);
        if (it == towers.end()) {
            towers.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << towers.size() << endl;
    return 0;
}