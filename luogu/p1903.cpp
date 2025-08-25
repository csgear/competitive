// https://www.luogu.com.cn/problem/P1903

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 200001;
const int Q = 200001;
const int V = 1000001;

struct Query {
    int l, r, t, id;
};

struct Update {
    int pos, val;
};

int n, m;
int a[N];
int cnt[V];
Query qry[Q];
Update upd[Q];
int ans[Q];
int cntq, cntu;
int res = 0;

void add(int val) {
    if (cnt[val]++ == 0) {
        res++;
    }
}

void remove(int val) {
    if (--cnt[val] == 0) {
        res--;
    }
}

void moveTime(int l, int r, int t) {
    int pos = upd[t].pos;
    int val = upd[t].val;
    if (l <= pos && pos <= r) {
        remove(a[pos]);
        add(val);
    }
    int tmp = a[pos];
    a[pos] = val;
    upd[t].val = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    char op;
    for (int i = 0, l, r, pos, val; i < m; i++) {
        cin >> op;
        if (op == 'Q') {
            cin >> l >> r;
            cntq++;
            qry[cntq].l = l;
            qry[cntq].r = r;
            qry[cntq].t = cntu;
            qry[cntq].id = cntq;
        } else {
            cin >> pos >> val;
            cntu++;
            upd[cntu].pos = pos;
            upd[cntu].val = val;
        }
    }
    int block_size = sqrt(n);

    sort(qry + 1, qry + cntq + 1, [block_size](const Query &a, const Query &b) {
        if (a.l / block_size != b.l / block_size) return a.l / block_size < b.l / block_size;
        if (a.r / block_size != b.r / block_size) return a.r / block_size < b.r / block_size;
        return a.t < b.t;
    });

    for (int i = 1, l = 1, r = 0, t = 0; i <= cntq; i++) {
        while (l < qry[i].l) remove(a[l++]);
        while (l > qry[i].l) add(a[--l]);
        while (r < qry[i].r) add(a[++r]);
        while (r > qry[i].r) remove(a[r--]);
        while (t < qry[i].t) {
            moveTime(l, r, ++t);
        }
        while (t > qry[i].t) {
            moveTime(l, r, t--);
        }
        ans[qry[i].id] = res;
    }

    for (int i = 1; i <= cntq; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}