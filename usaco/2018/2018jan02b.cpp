// https://usaco.org/index.php?page=viewproblem2&cpid=784
// USACO 2018 January Contest, Bronze
// Problem 2. Lifeguards

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bitset<1001>> shifts(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        for (int t = start; t < end; t++) {
            shifts[i][t] = 1;
        }
    }

    int maxCoverage = 0;

    for (int fire = 0; fire < n; fire++) {
        bitset<1001> coverage;

        for (int i = 0; i < n; i++) {
            if (i != fire) {
                coverage |= shifts[i];
            }
        }

        maxCoverage = max(maxCoverage, (int)coverage.count());
    }

    cout << maxCoverage << endl;

    return 0;
}
