// https://cses.fi/problemset/task/3219

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    set<int> missing;

    for (int i = 0; i <= k; i++) {
        missing.insert(i);
    }

    auto add = [&](int x) {
        if (x <= k) {
            freq[x]++;
            if (freq[x] == 1) {
                missing.erase(x);
            }
        }
    };

    auto remove = [&](int x) {
        if (x <= k) {
            freq[x]--;
            if (freq[x] == 0) {
                missing.insert(x);
                freq.erase(x);
            }
        }
    };

    auto getMex = [&]() { return *missing.begin(); };

    for (int i = 0; i < k; i++) {
        add(arr[i]);
    }
    cout << getMex() << " ";

    for (int i = k; i < n; i++) {
        remove(arr[i - k]);
        add(arr[i]);
        cout << getMex() << " ";
    }

    return 0;
}
