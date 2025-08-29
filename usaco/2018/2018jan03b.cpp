// https://usaco.org/index.php?page=viewproblem2&cpid=785
// USACO 2018 January Contest, Bronze
// Problem 3. Out of Place

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    int different = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != sorted_a[i]) {
            different++;
        }
    }

    cout << different - 1 << endl;

    return 0;
}