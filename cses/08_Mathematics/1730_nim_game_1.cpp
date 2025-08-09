// https://cses.fi/problemset/task/1730

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> piles(n);
        for (int i = 0; i < n; i++) {
            cin >> piles[i];
        }

        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            xor_sum ^= piles[i];
        }

        if (xor_sum != 0) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }

    return 0;
}