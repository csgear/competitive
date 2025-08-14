// https://cses.fi/problemset/task/2214/

#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;

    int l = 1, r = n;
    for (int i = 1; i <= n; ++i) {
        int left = n - i;  // The amount of numbers left.
        if (left <= k) {
            k -= left;
            // place largest remaining number (creates 'left' inversions)
            cout << r-- << ' ';
        } else {
            // place smallest remaining number (creates 0 inversions)
            cout << l++ << ' ';
        }
    }
    cout << '\n';
}
