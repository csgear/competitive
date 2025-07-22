// https://cses.fi/problemset/task/1731

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

int trie[MAXN][26];
bool isEnd[MAXN];
int nodeCount = 0;

void insert(const string& word) {
    int curr = 0;
    for (char c : word) {
        int idx = c - 'a';
        if (trie[curr][idx] == 0) {
            trie[curr][idx] = ++nodeCount;
        }
        curr = trie[curr][idx];
    }
    isEnd[curr] = true;
}

vector<int> findMatches(const string& s, int start) {
    vector<int> matches;
    int curr = 0;

    for (int i = start; i < s.length(); i++) {
        int idx = s[i] - 'a';
        if (trie[curr][idx] == 0) {
            break;
        }
        curr = trie[curr][idx];
        if (isEnd[curr]) {
            matches.push_back(i - start + 1);
        }
    }
    return matches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        insert(word);
    }

    int len = s.length();
    vector<long long> dp(len + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < len; ++i) {
        if (dp[i] == 0) continue;

        vector<int> matches = findMatches(s, i);
        for (int wordLen : matches) {
            dp[i + wordLen] = (dp[i + wordLen] + dp[i]) % MOD;
        }
    }

    cout << dp[len] << '\n';
    return 0;
}