// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        // even numbers first
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        // odd numbers second
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }
}