// https://usaco.org/index.php?page=viewproblem2&cpid=571
// USACO 2015 December Contest, Silver
// Problem 2. High Card Wins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> elsie(n);
    for (int i = 0; i < n; i++) {
        cin >> elsie[i];
    }

    sort(elsie.begin(), elsie.end());

    set<int> bessie;
    int j = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (j < n && i == elsie[j]) {
            j++;
        } else {
            bessie.insert(i);
        }
    }

    int wins = 0;
    for (int i = 0; i < n; i++) {
        auto it = bessie.upper_bound(elsie[i]);
        if (it != bessie.end()) {
            wins++;
            bessie.erase(it);
        }
    }

    cout << wins << endl;

    return 0;
}