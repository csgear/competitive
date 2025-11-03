// https://www.acwing.com/problem/content/952/
// 950. 郁闷的出纳员

#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INF = 1e9;

struct Node {
    int s[2], p, v;
    int size;
    void init(int _v, int _p) {
        s[0] = s[1] = 0;
        p = _p;
        v = _v;
        size = 1;
    }
} tr[N];

int root, idx;
int n, m, delta;

void push_up(int x) { tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1; }

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = (tr[y].s[1] == x);
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    push_up(y), push_up(x);
}

void splay(int x, int goal) {
    while (tr[x].p != goal) {
        int y = tr[x].p, z = tr[y].p;
        if (z != goal) {
            if ((tr[z].s[1] == y) ^ (tr[y].s[1] == x))
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
    if (goal == 0) root = x;
}

int insert(int v) {
    int u = root, p = 0;
    while (u) {
        p = u, u = tr[u].s[v > tr[u].v];
    }
    u = ++idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);
    return u;
}

int get(int v) {
    int u = root, res = 0;
    while (u) {
        if (tr[u].v >= v)
            res = u, u = tr[u].s[0];
        else
            u = tr[u].s[1];
    }
    return res;
}

int get_kth(int k) {
    int u = root;
    while (u) {
        int left_size = tr[tr[u].s[0]].size;
        if (k <= left_size) {
            u = tr[u].s[0];
        } else if (k == left_size + 1) {
            return tr[u].v;
        } else {
            k -= left_size + 1;
            u = tr[u].s[1];
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;

    int tot = 0;
    int L = insert(-INF);
    int R = insert(INF);
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I') {
            if (x >= m) {
                x -= delta;
                insert(x);
                tot++;
            }
        } else if (op == 'A') {
            delta += x;
        } else if (op == 'S') {
            delta -= x;
            R = get(m - delta);
            splay(R, 0), splay(L, R);
            tr[L].s[1] = 0;
            push_up(L), push_up(R);
        } else {
            int cnt = tr[root].size - 2;
            if (cnt < x) {
                cout << -1 << endl;
            } else {
                cout << get_kth(cnt - x + 2) + delta << endl;
            }
        }
    }

    cout << tot - (tr[root].size - 2) << endl;

    return 0;
}
