// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5;
int x[N];

int main() {
    int n;
    cin >> n;

    indexed_set<int> s;

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        s.insert(i);
    }

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        auto it = s.find_by_order(p - 1);
        int pos = *it;
        cout << x[pos] << ' ';
        s.erase(it);
    }
    cout << '\n';
}