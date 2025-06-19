// https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
    vector<T> tree;
    int n;

    void build(vector<T>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left - 1];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, idx * 2, left, mid);
        build(arr, idx * 2 + 1, mid + 1, right);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }

    T query(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return 0;            // no overlap
        if (ql <= left && right <= qr) return tree[idx];  // total overlap

        int mid = (left + right) / 2;
        T leftSum = query(idx * 2, left, mid, ql, qr);
        T rightSum = query(idx * 2 + 1, mid + 1, right, ql, qr);
        return leftSum + rightSum;
    }

   public:
    SegmentTree(vector<T>& arr) {
        n = arr.size();
        tree.resize(n * 4);
        build(arr, 1, 1, n);
    }
    T query(int l, int r) { return query(1, 1, n, l, r); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    SegmentTree<long long> seg(arr);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << seg.query(l, r) << endl;
    }
    return 0;
}
