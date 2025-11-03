// https://atcoder.jp/contests/abc430/tasks/abc430_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int L = -1;
const int R = 1e9 + 1;
const int N = 5e5 + 5;

int d[N];
set<int> s;
map<int, int> mp;  // pos -> index
int n;
ll ans;

void cal(set<int>::iterator it) {
    int pos = *it;
    int idx = mp[pos];
    if (idx == -1) return;
    ans -= d[idx];
    d[idx] = 2e9;
    it++;
    int r = *it;
    int idr = mp[r];
    if (idr != -1) {
        d[idx] = min(d[idx], r - pos);
    }
    it--, it--;
    int l = *it;
    int idl = mp[l];
    if (idl != -1) {
        d[idx] = min(d[idx], pos - l);
    }
    ans += d[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    ans = 0;
    s.insert(L), s.insert(0), s.insert(R);
    mp[L] = -1, mp[0] = 0, mp[R] = -1;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = s.insert(x).first;
        mp[x] = i;
        cal(it);
        it++;
        cal(it);
        it--, it--;
        cal(it);
        cout << ans << '\n';
    }
    return 0;
}