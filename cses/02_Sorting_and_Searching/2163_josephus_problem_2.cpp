// https://cses.fi/problemset/task/2163

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// using balanced binary search tree
void josephus_order_tree(int n, int k) {
    ordered_set os;
    for (int i = 1; i <= n; ++i) os.insert(i);
    int idx = 0;
    while (os.size() > 1) {
        idx = (idx + k - 1) % os.size();
        cout << *os.find_by_order(idx) << " ";
        os.erase(os.find_by_order(idx));
    }
    cout << *os.begin() << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    josephus_order_tree(n, k + 1);
    return 0;
}