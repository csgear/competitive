// https://cses.fi/problemset/task/3224

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> freq;
    map<int, set<int>> freqCount;

    auto add = [&](int x) {
        if (freq[x] > 0) {
            freqCount[freq[x]].erase(x);
            if (freqCount[freq[x]].empty()) {
                freqCount.erase(freq[x]);
            }
        }
        freq[x]++;
        freqCount[freq[x]].insert(x);
    };

    auto remove = [&](int x) {
        freqCount[freq[x]].erase(x);
        if (freqCount[freq[x]].empty()) {
            freqCount.erase(freq[x]);
        }

        freq[x]--;
        if (freq[x] > 0) {
            freqCount[freq[x]].insert(x);
        } else {
            freq.erase(x);
        }
    };

    auto getMode = [&]() {
        int maxFreq = freqCount.rbegin()->first;
        return *freqCount[maxFreq].begin();
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
            cout << getMode() << " ";
        }
    }
    return 0;
}
