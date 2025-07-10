// https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll>& songs) {
    ll start = 1, ans = 0;

    map<ll, ll> mp;

    for (ll end = 1; end <= n; end++) {
        if (mp.find(songs[end]) == mp.end())
            mp.insert({songs[end], end});
        else {
            if (mp[songs[end]] >= start) start = mp[songs[end]] + 1;
            mp[songs[end]] = end;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> songs(n);

    for (ll i = 1; i <= n; i++) {
        cin >> songs[i];
    }

    cout << solve(n, songs) << endl;
    return 0;
}