#include <bits/stdc++.h>
using namespace std;

int maxRotation(const vector<int>& a, const vector<int>& b, int k) {
    unordered_map<int, int> pos;
    for (int i = 0; i < k; ++i) pos[a[i]] = i;

    vector<int> cnt(k);
    for (int i = 0; i < k; ++i) {
        if (pos.count(b[i])) {
            int offset = (i - pos[b[i]] + k) % k;
            cnt[offset]++;
        }
    }
    return *max_element(cnt.begin(), cnt.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(k), b(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];

    set<int> outside;
    for (int i = 1; i <= n; ++i) outside.insert(i);
    for (int x : a) outside.erase(x);
    for (int x : b) outside.erase(x);

    vector<int> bRev = b;
    reverse(bRev.begin(), bRev.end());

    cout << outside.size() + max(maxRotation(a, b, k), maxRotation(a, bRev, k)) << '\n';

    return 0;
}