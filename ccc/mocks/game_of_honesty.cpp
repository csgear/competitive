// https://dmoj.ca/problem/oly19practice43

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

class SegementTree {
   private:
    int n;
    vector<int> tree, lazy;

   public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, INF);
        lazy.assign(4 * n, INF);
    }

    bool has_value(int l, int r, int val) { return query(1, 1, n, l, r, val) > 0; }
}

int main() {
    return 0;
}