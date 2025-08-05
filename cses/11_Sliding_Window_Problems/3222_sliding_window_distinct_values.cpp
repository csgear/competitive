// https://cses.fi/problemset/task/3222

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq;
    int ans = 0;
    queue<int> window;

    auto add = [&](int x) {
        if (freq[x] == 0) {
            ans++;
        }
        freq[x]++;
    };

    auto remove = [&](int x) {
        freq[x]--;
        if (freq[x] == 0) {
            freq.erase(x);
            ans--;
        }
    };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
        window.push(x);

        if (window.size() > k) {
            remove(window.front());
            window.pop();
        }

        if (window.size() == k) {
            cout << ans << " ";
        }
    }
    return 0;
}
