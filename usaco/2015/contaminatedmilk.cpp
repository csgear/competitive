// Contaminated Milk【USACO 2015 December Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    vector<array<int, 3>> drinks(d);
    for (int i = 0; i < d; ++i) cin >> drinks[i][0] >> drinks[i][1] >> drinks[i][2];
    vector<array<int, 2>> sick(s);
    for (int i = 0; i < s; ++i) cin >> sick[i][0] >> sick[i][1];

    set<int> possible;
    for (int milk = 1; milk <= m; ++milk) {
        bool ok = true;
        for (int i = 0; i < s; ++i) {
            bool found = false;
            for (int j = 0; j < d; ++j)
                if (drinks[j][0] == sick[i][0] && drinks[j][1] == milk && drinks[j][2] < sick[i][1])
                    found = true;
            if (!found) ok = false;
        }
        if (ok) possible.insert(milk);
    }

    int ans = 0;
    for (int milk : possible) {
        set<int> drank;
        for (int i = 0; i < d; ++i)
            if (drinks[i][1] == milk) drank.insert(drinks[i][0]);
        ans = max(ans, (int)drank.size());
    }
    cout << ans << endl;
}