// https://cses.fi/problemset/task/1731

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    set<string> words;

    for (int i = 0; i < n; ++i) {
        string ss;
        cin >> ss;
        words.insert(ss);
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (const string& word : words) {
            int wordLen = word.size();
            if (wordLen <= i) {
                bool matches = true;
                for (int j = 0; j < wordLen; j++) {
                    if (s[i - wordLen + j] != word[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    dp[i] = (dp[i] + dp[i - wordLen]) % MOD;
                }
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}