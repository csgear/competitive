// https://www.acwing.com/problem/content/1119/

#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int g[N][N];
string word[N];
int used[N];
int n, ans;

void dfs(string s, int i) {
    ans = max(ans, (int)s.size());
    used[i]++;
    for (int j = 0; j < n; j++) {
        if (used[j] < 2 && g[i][j]) {
            dfs(s + word[j].substr(g[i][j]), j);
        }
    }
    used[i]--;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> word[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 1; k <= min(word[i].size(), word[j].size()); k++) {
                if (word[i].substr(word[i].size() - k) == word[j].substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    char start;
    cin >> start;
    for (int i = 0; i < n; i++) {
        if (word[i][0] == start) {
            dfs(word[i], i);
        }
    }
    cout << ans << endl;
    return 0;
}