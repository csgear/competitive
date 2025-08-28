// https://usaco.org/index.php?page=viewproblem2&cpid=760

// USACO 2017 December Contest, Bronze
// Problem 2. The Bovine Shuffle

#include <bits/stdc++.h>
using namespace std;

const int SHUFFLE_NUM = 3;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        cin >> ids[i];
    }

    for (int i = 0; i < SHUFFLE_NUM; i++) {
        vector<int> past_ids(n);
        for (int j = 0; j < n; j++) {
            // normal shuffle: id[a[j] - 1] = id[j]
            // reverse shuffle: id[j] = id[a[j] - 1]
            past_ids[j] = ids[a[j] - 1];
        }
        ids = past_ids;
    }

    for (int i = 0; i < n; i++) {
        cout << ids[i] << '\n';
    }

    return 0;
}