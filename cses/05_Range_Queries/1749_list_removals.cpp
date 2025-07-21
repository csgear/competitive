// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
int tree[N << 2];

void push_up(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

void build(int p, int pl, int pr) {
    if (pl == pr) {
        tree[p] = 1;
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p);
}

int remove_kth(int k, int p, int pl, int pr) {
    if (pl == pr) {
        tree[p] = 0;
        return pl;
    }
    int mid = (pl + pr) >> 1;
    int res;
    if (tree[p << 1] >= k) {
        res = remove_kth(k, p << 1, pl, mid);
    } else {
        res = remove_kth(k - tree[p << 1], p << 1 | 1, mid + 1, pr);
    }
    push_up(p);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int idx = remove_kth(k, 1, 1, n);
        cout << a[idx] << " ";
    }
    cout << "\n";
    return 0;
}