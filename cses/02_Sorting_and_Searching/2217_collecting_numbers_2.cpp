// https://cses.fi/problemset/task/2217

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[values[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i - 1] > pos[i]) {
            rounds++;
        }
    }

    int l, r;
    set<pair<int, int>> updates;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        if (values[l] + 1 <= n) {
            updates.insert({values[l], values[l] + 1});
        }
        if (values[l] - 1 >= 1) {
            updates.insert({values[l] - 1, values[l]});
        }
        if (values[r] + 1 <= n) {
            updates.insert({values[r], values[r] + 1});
        }
        if (values[r] - 1 >= 1) {
            updates.insert({values[r] - 1, values[r]});
        }

        for (auto [l1, r1] : updates) {
            rounds -= pos[l1] > pos[r1];
        }
        swap(values[l], values[r]);
        pos[values[l]] = l;
        pos[values[r]] = r;
        for (auto [l1, r1] : updates) {
            rounds += pos[l1] > pos[r1];
        }
        cout << rounds << endl;
        updates.clear();
    }

    return 0;
}