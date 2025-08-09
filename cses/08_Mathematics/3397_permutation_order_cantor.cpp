// https://cses.fi/problemset/task/3397
// Permutation Order - 康托展开 (Cantor Expansion) with BIT optimization

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 20;
ll fact[MAXN + 1];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// Binary Indexed Tree for efficient range queries
struct BIT {
    vector<int> tree;
    int n;

    BIT(int size) : n(size) { tree.assign(n + 1, 0); }

    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    // Find k-th smallest available element (1-indexed)
    int find_kth(int k) {
        int pos = 0;
        for (int bit = 20; bit >= 0; bit--) {
            if (pos + (1 << bit) <= n && query(pos + (1 << bit)) < k) {
                pos += (1 << bit);
            }
        }
        return pos + 1;
    }
};

// 康托展开：排列 → 排名
ll cantor_expansion(const vector<int>& perm) {
    int n = perm.size();
    BIT bit(n);

    // 初始化BIT，所有位置都可用
    for (int i = 1; i <= n; i++) {
        bit.update(i, 1);
    }

    ll rank = 0;

    for (int i = 0; i < n; i++) {
        // 计算有多少个比当前元素小的未使用元素
        int smaller = bit.query(perm[i] - 1);
        rank += smaller * fact[n - 1 - i];

        // 标记当前元素为已使用
        bit.update(perm[i], -1);
    }

    return rank + 1;  // 转换为1-indexed
}

// 康托展开逆运算：排名 → 排列
vector<int> inverse_cantor_expansion(int n, ll k) {
    BIT bit(n);

    // 初始化BIT，所有位置都可用
    for (int i = 1; i <= n; i++) {
        bit.update(i, 1);
    }

    vector<int> perm(n);
    k--;  // 转换为0-indexed

    for (int i = 0; i < n; i++) {
        // 计算当前位置应该放第几小的可用元素
        int order = k / fact[n - 1 - i] + 1;  // 1-indexed

        // 找到第order小的可用元素
        int element = bit.find_kth(order);
        perm[i] = element;

        // 标记该元素为已使用
        bit.update(element, -1);

        k %= fact[n - 1 - i];
    }

    return perm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // 给定 n 和 k，求第 k 个排列
            int n;
            ll k;
            cin >> n >> k;

            vector<int> perm = inverse_cantor_expansion(n, k);
            for (int i = 0; i < n; i++) {
                cout << perm[i];
                if (i < n - 1) cout << " ";
            }
            cout << "\n";
        } else {
            // 给定 n 和排列，求排名
            int n;
            cin >> n;
            vector<int> perm(n);
            for (int i = 0; i < n; i++) {
                cin >> perm[i];
            }

            ll k = cantor_expansion(perm);
            cout << k << "\n";
        }
    }

    return 0;
}
