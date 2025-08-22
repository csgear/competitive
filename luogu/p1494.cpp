// https://www.luogu.com.cn/problem/P1494
// 普通莫队模板题

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 50005;
const int Q = 50005;
const int V = 50005;

struct Query {
    int l, r, id;
};

int n, q;
int a[N];
int cnt[V];
Query qry[Q];
LL ans1[Q];
LL ans2[Q];
LL res = 0;

void add(int i) {
    res -= cnt[a[i]] * cnt[a[i]];
    cnt[a[i]]++;
    res += cnt[a[i]] * cnt[a[i]];
}

void remove(int i) {
    res -= cnt[a[i]] * cnt[a[i]];
    cnt[a[i]]--;
    res += cnt[a[i]] * cnt[a[i]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
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
        if (qry[i].r == qry[i].l) {
            ans1[qry[i].id] = 0;
            ans2[qry[i].id] = 1;
        } else {
            ans1[qry[i].id] = res - (qry[i].r - qry[i].l + 1);
            ans2[qry[i].id] = 1LL * (qry[i].r - qry[i].l + 1) * (qry[i].r - qry[i].l);
            LL g = gcd(ans1[qry[i].id], ans2[qry[i].id]);
            ans1[qry[i].id] /= g;
            ans2[qry[i].id] /= g;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans1[i] << "/" << ans2[i] << endl;
    }

    return 0;
}