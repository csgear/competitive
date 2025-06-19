// https://dmoj.ca/problem/oly24practice2

#include <bits/stdc++.h>

using namespace std;
int tree[400005][10], lazy[400005][27];
char s[100005];

void build(int i, int L, int R) {
    if (L == R) {
        tree[i][s[L] - 'a'] = 1;
        for (int j = 0; j < 26; j++) lazy[i][j] = -1;
        return;
    }
    build(i * 2 + 1, L, (L + R) / 2);
    build(i * 2 + 2, (L + R) / 2 + 1, R);
    for (int j = 0; j < 26; j++) {
        lazy[i][j] = -1;
        tree[i][j] = tree[i * 2 + 1][j] + tree[i * 2 + 2][j];
    }
}

void update(int i, int L, int R, int x, int y, int val, int j) {
    if (lazy[i][j] != -1) {
        tree[i][j] = lazy[i][j] * (R - L + 1);
        if (L != R) {
            lazy[i * 2 + 1][j] = lazy[i][j];
            lazy[i * 2 + 2][j] = lazy[i][j];
        }
        lazy[i][j] = -1;
    }
    if (L >= x && R <= y) {
        lazy[i][j] = val;
        tree[i][j] = lazy[i][j] * (R - L + 1);
        if (L != R) {
            lazy[i * 2 + 1][j] = lazy[i][j];
            lazy[i * 2 + 2][j] = lazy[i][j];
        }
        lazy[i][j] = -1;
        return;
    }
    if (L > y || R < x) return;
    update(i * 2 + 1, L, (L + R) / 2, x, y, val, j);
    update(i * 2 + 2, (L + R) / 2 + 1, R, x, y, val, j);
    tree[i][j] = tree[i * 2 + 1][j] + tree[i * 2 + 2][j];
}

int query(int i, int L, int R, int x, int y, int j) {
    if (lazy[i][j] != -1) {
        tree[i][j] = lazy[i][j] * (R - L + 1);
        if (L != R) {
            lazy[i * 2 + 1][j] = lazy[i][j];
            lazy[i * 2 + 2][j] = lazy[i][j];
        }
        lazy[i][j] = -1;
    }
    if (L >= x && R <= y) return tree[i][j];
    if (L > y || R < x) return 0;
    return query(i * 2 + 1, L, (L + R) / 2, x, y, j) +
           query(i * 2 + 2, (L + R) / 2 + 1, R, x, y, j);
}

void get(int i, int L, int R, int j) {
    if (lazy[i][j] != -1) {
        tree[i][j] = lazy[i][j] * (R - L + 1);
        if (L != R) {
            lazy[i * 2 + 1][j] = lazy[i][j];
            lazy[i * 2 + 2][j] = lazy[i][j];
        }
        lazy[i][j] = -1;
    }
    if (!tree[i][j]) return;
    if (L == R) {
        s[L] = j + 'a';
        return;
    }
    get(i * 2 + 1, L, (L + R) / 2, j);
    get(i * 2 + 2, (L + R) / 2 + 1, R, j);
}

int cnt[26];

int main() {
    int n, q, x, y, up;
    scanf("%d %d", &n, &q);
    scanf("%s", s);
    build(0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &x, &y, &up);
        x--, y--;
        for (int j = 0; j < 26; j++) cnt[j] = query(0, 0, n - 1, x, y, j);
        int curr = x;
        if (!up) curr = y;
        for (int j = 0; j < 26; j++) {
            if (!cnt[j]) continue;
            update(0, 0, n - 1, x, y, 0, j);
            if (up) {
                update(0, 0, n - 1, curr, curr + cnt[j] - 1, 1, j);
                curr += cnt[j];
            } else {
                update(0, 0, n - 1, curr - cnt[j] + 1, curr, 1, j);
                curr -= cnt[j];
            }
        }
    }
    for (int i = 0; i < 26; i++) get(0, 0, n - 1, i);
    printf("%s", s);
    return 0;
}
