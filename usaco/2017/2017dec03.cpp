// https://usaco.org/index.php?page=viewproblem2&cpid=761
// USACO 2017 December Contest, Bronze
// Problem 3. Milk Measurement

#include <bits/stdc++.h>
using namespace std;

struct entry {
    int day;
    string cow;
    int change;
};

int main() {
    int n;
    cin >> n;

    vector<entry> entries(n);

    for (int i = 0; i < n; i++) {
        cin >> entries[i].day >> entries[i].cow >> entries[i].change;
    }

    sort(entries.begin(), entries.end(),
         [](const entry& a, const entry& b) { return a.day < b.day; });

    int prev_leaders = 7;
    int ans = 0;
    int b = 7, e = 7, m = 7;

    for (auto& entry : entries) {
        if (entry.cow == "Bessie")
            b += entry.change;
        else if (entry.cow == "Elsie")
            e += entry.change;
        else if (entry.cow == "Mildred")
            m += entry.change;

        int cur_max = max(b, max(e, m));
        int cur_leaders = 0;
        if (b == cur_max) cur_leaders |= 1;
        if (e == cur_max) cur_leaders |= 2;
        if (m == cur_max) cur_leaders |= 4;

        if (cur_leaders != prev_leaders) {
            ans++;
            prev_leaders = cur_leaders;
        }
    }

    cout << ans << endl;
    return 0;
}