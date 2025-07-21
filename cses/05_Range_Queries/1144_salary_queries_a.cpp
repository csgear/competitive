// https://cses.fi/problemset/task/1144

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;

const int MAX_N = 2e5 + 5;

char c;
int N, Q, a, b, p[MAX_N];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> T;

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        T.insert({p[i], i});
    }

    for (int i = 0; i < Q; i++) {
        scanf(" %c %d %d", &c, &a, &b);
        if (c == '!') {
            T.erase({p[a], a});
            T.insert({b, a});
            p[a] = b;
        } else if (c == '?') {
            printf("%ld\n", T.order_of_key({b + 1, 0}) - T.order_of_key({a, 0}));
        }
    }
}