// https://cses.fi/problemset/task/2168
// Using BIT template style from 1748, output binary (0/1)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;  // 2n coordinates max

int lowbit(int x) { return x & -x; }

int tree1[MAXN], tree2[MAXN];
int n_coords;

void update(int tree[], int idx, int val) {
    for (int i = idx; i <= n_coords; i += lowbit(i)) {
        tree[i] += val;
    }
}

int query(int tree[], int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

int rangeQuery(int tree[], int left, int right) {
    return query(tree, right) - query(tree, left - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> ranges(n);  // {start, end, original_index}
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
        coords.push_back(ranges[i][0]);
        coords.push_back(ranges[i][1]);
    }

    // Coordinate compression
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    n_coords = coords.size();

    auto compress = [&](int x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin() + 1;
    };

    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    // Count "contains" - sort by start asc, then end desc
    sort(ranges.begin(), ranges.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });

    // Clear BIT arrays
    for (int i = 0; i <= n_coords; i++) tree1[i] = tree2[i] = 0;

    // Process from right to left to count "contains"
    for (int i = n - 1; i >= 0; i--) {
        int end_compressed = compress(ranges[i][1]);
        contains[ranges[i][2]] = query(tree1, end_compressed);
        update(tree1, end_compressed, 1);
    }

    // Count "contained_by" - sort by start desc, then end asc
    sort(ranges.begin(), ranges.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        if (a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    });

    // Process from right to left to count "contained_by"
    for (int i = n - 1; i >= 0; i--) {
        int end_compressed = compress(ranges[i][1]);
        contained_by[ranges[i][2]] = rangeQuery(tree2, end_compressed, n_coords);
        update(tree2, end_compressed, 1);
    }

    // Output results - binary (0 if count is 0, 1 if count > 0)
    for (int i = 0; i < n; i++) {
        cout << (contains[i] > 0 ? 1 : 0);
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << (contained_by[i] > 0 ? 1 : 0);
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
