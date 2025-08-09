// https://cses.fi/problemset/task/1099

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);

        int xor_sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (i % 2 == 0) xor_sum ^= p[i];  // XOR even-indexed stairs
        }

        if (xor_sum != 0) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }

    return 0;
}