// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
    vector<T> sm;
    vector<T> mn, mx;
    int n;

    static constexpr T INF = std::numeric_limits<T>::max();  // for min queries

    void build(vector<T>& arr, int idx, int left, int right) {
        if (left == right) {
            sm[idx] = arr[left - 1];
            mn[idx] = arr[left - 1];
            mx[idx] = arr[left - 1];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, idx * 2, left, mid);
        build(arr, idx * 2 + 1, mid + 1, right);
        sm[idx] = sm[idx * 2] + sm[idx * 2 + 1];
        mn[idx] = min(mn[idx * 2], mn[idx * 2 + 1]);
        mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
    }

    T query_min(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return INF;
        if (ql <= left && right <= qr) return mn[idx];
        int mid = (left + right) / 2;
        return min(query_min(idx * 2, left, mid, ql, qr),
                   query_min(idx * 2 + 1, mid + 1, right, ql, qr));
    }

    T query_max(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return -INF;
        if (ql <= left && right <= qr) return mx[idx];
        int mid = (left + right) / 2;
        return max(query_max(idx * 2, left, mid, ql, qr),
                   query_max(idx * 2 + 1, mid + 1, right, ql, qr));
    }

    T query(int idx, int left, int right, int ql, int qr) {
        int mid = (left + right) / 2;
        T leftSum = query(idx * 2, left, mid, ql, qr);
        T rightSum = query(idx * 2 + 1, mid + 1, right, ql, qr);
        return leftSum + rightSum;
    }

   public:
    SegmentTree(vector<T>& arr) {
        n = arr.size();
        sm.resize(n * 4);
        mn.resize(n * 4);
        mx.resize(n * 4);
        build(arr, 1, 1, n);
    }
    T query(int l, int r) { return query_min(1, 1, n, l, r); }
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
