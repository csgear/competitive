// https://cses.fi/problemset/task/1076

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<int> left, right;
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto balance = [&]() {
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        }
        while (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };

    auto add = [&](int x) {
        if (left.empty() || x <= *left.rbegin()) {
            left.insert(x);
        } else {
            right.insert(x);
        }
        balance();
    };

    auto remove = [&](int x) {
        if (left.count(x)) {
            left.erase(left.find(x));
        } else {
            right.erase(right.find(x));
        }
        balance();
    };

    for (int i = 0; i < n; i++) {
        add(arr[i]);
        if (i >= k - 1) {
            cout << *left.rbegin() << " ";
            remove(arr[i - k + 1]);
        }
    }

    return 0;
}
