// https://cses.fi/problemset/task/3112
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int left = 1, right = 1000000000;

    while (left < right) {
        int mid = left + (right - left) / 2;

        cout << "? " << mid << endl;
        cout.flush();

        string response;
        cin >> response;

        if (response == "YES") {
            // mid < x, so x is in (mid, right]
            left = mid + 1;
        } else {
            // mid >= x, so x is in [left, mid]
            right = mid;
        }
    }

    cout << "! " << left << endl;
    cout.flush();

    return 0;
}