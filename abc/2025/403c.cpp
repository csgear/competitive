// https://atcoder.jp/contests/abc403/tasks/abc403_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> v[200005];
    bool all[200005];

    int N, M, Q;

    cin >> N >> M >> Q;

    for (int i = 0; i < Q; i++) {
        int q, x, y;
        cin >> q;
        if (q == 1) {
            cin >> x >> y;
            v[x].insert(y);
        } else if (q == 2) {
            cin >> x;
            all[x] = true;
        } else if (q == 3) {
            cin >> x >> y;
            if (all[x] || v[x].find(y) != v[x].end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
