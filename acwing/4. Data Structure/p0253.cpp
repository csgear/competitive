// https://www.acwing.com/problem/content/255/
// template treap implementation

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int INF = 1e8;

struct Node {
    int l, r;
    int key, val;   // key: value, val: random priority
    int cnt, size;  // cnt: duplicate count, size: subtree size
} tr[N];

int root, idx;

// Update subtree size
void pushup(int p) { tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt; }

// Create new node
int new_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    tr[idx].l = tr[idx].r = 0;
    return idx;
}

// Right rotate (zig)
void zig(int& p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    pushup(p);
    pushup(q);
    p = q;
}

// Left rotate (zag)
void zag(int& p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    pushup(p);
    pushup(q);
    p = q;
}

// Insert key into Treap
void insert(int& p, int key) {
    if (!p) {
        p = new_node(key);
        return;
    }
    if (tr[p].key == key) {
        tr[p].cnt++;
    } else if (key < tr[p].key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}

// Remove key from Treap
void remove(int& p, int key) {
    if (!p) return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) {
            tr[p].cnt--;
        } else {
            if (!tr[p].l || !tr[p].r) {
                p = tr[p].l + tr[p].r;  // one child or none
            } else {
                if (tr[tr[p].l].val > tr[tr[p].r].val) {
                    zig(p);
                    remove(tr[p].r, key);
                } else {
                    zag(p);
                    remove(tr[p].l, key);
                }
            }
        }
    } else if (key < tr[p].key) {
        remove(tr[p].l, key);
    } else {
        remove(tr[p].r, key);
    }
    if (p) pushup(p);
}

// Get rank of key (number of elements < key) + 1
int get_rank(int p, int key) {
    if (!p) return 0;
    if (tr[p].key == key) {
        return tr[tr[p].l].size + 1;
    } else if (key < tr[p].key) {
        return get_rank(tr[p].l, key);
    } else {
        return tr[tr[p].l].size + tr[p].cnt + get_rank(tr[p].r, key);
    }
}

// Get k-th smallest element (1-indexed)
int get_kth(int p, int k) {
    if (!p) return -1;
    if (k <= tr[tr[p].l].size) {
        return get_kth(tr[p].l, k);
    } else if (k <= tr[tr[p].l].size + tr[p].cnt) {
        return tr[p].key;
    } else {
        return get_kth(tr[p].r, k - tr[tr[p].l].size - tr[p].cnt);
    }
}

// Get predecessor (< key, max)
int get_pre(int p, int key) {
    if (!p) return -INF;
    if (tr[p].key < key) {
        return max(tr[p].key, get_pre(tr[p].r, key));
    } else {
        return get_pre(tr[p].l, key);
    }
}

// Get successor (> key, min)
int get_suc(int p, int key) {
    if (!p) return INF;
    if (tr[p].key > key) {
        return min(tr[p].key, get_suc(tr[p].l, key));
    } else {
        return get_suc(tr[p].r, key);
    }
}

int main() {
    srand(time(0));  // for randomized priority
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    while (m--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            insert(root, x);
        } else if (op == 2) {
            remove(root, x);
        } else if (op == 3) {
            cout << get_rank(root, x) << '\n';
        } else if (op == 4) {
            cout << get_kth(root, x) << '\n';
        } else if (op == 5) {
            cout << get_pre(root, x) << '\n';
        } else if (op == 6) {
            cout << get_suc(root, x) << '\n';
        }
    }
    return 0;
}