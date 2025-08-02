// https://cses.fi/problemset/task/1077

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<int> left, right;
    ll leftSum = 0, rightSum = 0;

    auto balance = [&]() {
        while (left.size() > right.size() + 1) {
            int val = *left.rbegin();
            leftSum -= val;
            rightSum += val;
            left.erase(left.find(val));
            right.insert(val);
        }

        while (right.size() > left.size()) {
            int val = *right.begin();
            rightSum -= val;
            leftSum += val;
            right.erase(right.find(val));
            left.insert(val);
        }
    };

    auto add = [&](int x) {
        if (left.empty() || x <= *left.rbegin()) {
            left.insert(x);
            leftSum += x;
        } else {
            right.insert(x);
            rightSum += x;
        }
        balance();
    };

    auto remove = [&](int x) {
        if (left.find(x) != left.end()) {
            left.erase(left.find(x));
            leftSum -= x;
        } else {
            right.erase(right.find(x));
            rightSum -= x;
        }
        balance();
    };

    auto getCost = [&]() {
        int median = *left.rbegin();
        return (ll)median * left.size() - leftSum + rightSum - (ll)median * right.size();
    };

    for (int i = 0; i < n; i++) {
        add(arr[i]);

        if (i >= k - 1) {
            cout << getCost() << " ";
            remove(arr[i - k + 1]);
        }
    }

    return 0;
}
