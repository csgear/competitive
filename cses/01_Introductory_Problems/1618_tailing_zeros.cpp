// https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int zeros = 0;
    for (long long i = 5; n / i > 0; i *= 5) {
        zeros += n / i;
    }
    cout << zeros << '\n';
    return 0;
}
