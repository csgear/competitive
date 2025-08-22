// https://www.luogu.com.cn/problem/SP3267
// 普通莫队模板题

#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
const int Q = 200005;
const int V = 1000005;

struct Query {
    int l, r, id;
};

int n, q;
int a[N];
int cnt[V];
Query qry[Q];
int ans[Q];
int res = 0;

void add(int i) {
    if (cnt[a[i]]++ == 0) {
        res++;
    }
}

void remove(int i) {
    if (--cnt[a[i]] == 0) {
        res--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].id = i;
    }
    int block_size = sqrt(n);

    sort(qry, qry + q, [block_size](const Query &a, const Query &b) {
        return a.l / block_size != b.l / block_size ? a.l / block_size < b.l / block_size
                                                    : a.r < b.r;
    });

    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        while (l < qry[i].l) remove(l++);
        while (l > qry[i].l) add(--l);
        while (r < qry[i].r) add(++r);
        while (r > qry[i].r) remove(r--);
        ans[qry[i].id] = res;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}