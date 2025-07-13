// https://atcoder.jp/contests/abc414/tasks/abc414_c

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// flag true for odd length, false for even length
ll generate(int n, bool flag) {
    ll original = n;
    if (flag) {
        n /= 10;
    }
    ll ans = original;
    while (n > 0) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

bool check(ll n, int base) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % base);
        n /= base;
    }
    int left = 0, right = digits.size() - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int base;
    ll n;
    cin >> base >> n;
    ll sum = 0;

    for (int i = 1; i <= 1000000; i++) {
        ll x = generate(i, true);
        ll y = generate(i, false);

        if (x > n && y > n) {
            break;
        }

        if (x <= n && check(x, base)) {
            sum += x;
        }
        if (y <= n && check(y, base)) {
            sum += y;
        }
    }
    cout << sum << endl;
    return 0;
}