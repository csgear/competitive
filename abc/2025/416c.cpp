// https://atcoder.jp/contests/abc416/tasks/abc416_c

#include <bits/stdc++.h>
using namespace std;

int n, k, x;
vector<string> s, ans;

void dfs(int depth, string curr) {
    if (depth == k) {
        ans.push_back(curr);
        return;
    }
    for (int j = 0; j < n; j++) {
        dfs(depth + 1, curr + s[j]);
    }
}

int main() {
    cin >> n >> k >> x;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    dfs(0, "");
    if (x <= ans.size()) {
        cout << ans[x - 1] << endl;
    }
    return 0;
}