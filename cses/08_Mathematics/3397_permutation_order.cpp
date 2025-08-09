// https://cses.fi/problemset/task/3397
// Permutation Order - Convert between permutation and its lexicographic rank

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

// Convert rank k to permutation (1-indexed k)
vector<int> rank_to_permutation(int n, ll k) {
    vector<int> available;
    for (int i = 1; i <= n; i++) {
        available.push_back(i);
    }

    vector<int> perm(n);
    k--;  // Convert to 0-indexed

    for (int i = 0; i < n; i++) {
        int idx = k / fact[n - 1 - i];
        perm[i] = available[idx];
        available.erase(available.begin() + idx);
        k %= fact[n - 1 - i];
    }

    return perm;
}

// Convert permutation to rank (returns 1-indexed rank)
ll permutation_to_rank(const vector<int>& perm) {
    int n = perm.size();
    vector<int> available;
    for (int i = 1; i <= n; i++) {
        available.push_back(i);
    }

    ll rank = 0;

    for (int i = 0; i < n; i++) {
        int pos = find(available.begin(), available.end(), perm[i]) - available.begin();
        rank += pos * fact[n - 1 - i];
        available.erase(available.begin() + pos);
    }

    return rank + 1;  // Convert to 1-indexed
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
            // Given n and k, find p(n,k)
            int n;
            ll k;
            cin >> n >> k;

            vector<int> perm = rank_to_permutation(n, k);
            for (int i = 0; i < n; i++) {
                cout << perm[i];
                if (i < n - 1) cout << " ";
            }
            cout << "\n";
        } else {
            // Given n and permutation, find k
            int n;
            cin >> n;
            vector<int> perm(n);
            for (int i = 0; i < n; i++) {
                cin >> perm[i];
            }

            ll k = permutation_to_rank(perm);
            cout << k << "\n";
        }
    }

    return 0;
}
