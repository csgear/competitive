// https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// find the position of the person who will survive
int josephus_1_based(int n, int k) {
    int res = 1;  // Base case: J_1(1, k) = 1
    for (int i = 2; i <= n; ++i) {
        res = ((res + k - 2) % i) + 1;
    }
    return res;
}

// find the order of the people who will survive
// TLE when n == 2 * 10^5
void josephus_order(vector<int>& people, int k, int start, vector<int>& order) {
    if (people.empty()) return;
    int n = people.size();
    int idx = (start + k - 1) % n;
    order.push_back(people[idx]);
    people.erase(people.begin() + idx);
    josephus_order(people, k, idx, order);
}

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
    int n;
    int k = 2;
    cin >> n;
    josephus_order_tree(n, k);
    return 0;
}