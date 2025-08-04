// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    string combined = t + "#" + s;
    vector<int> z = z_function(combined);

    int count = 0;
    int pattern_len = t.size();

    for (int i = pattern_len + 1; i < combined.size(); i++) {
        if (z[i] == pattern_len) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
