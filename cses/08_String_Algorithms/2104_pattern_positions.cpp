// https://cses.fi/problemset/task/2104

#include <bits/stdc++.h>
using namespace std;

string s;
int n, cnt = 0, ans[500005], patLen[500005];
map<string, vector<int>> patternMap;  // map pattern to list of indices
vector<string> uniquePatterns;

struct Node {
    int fail, child[26] = {};
    vector<int> idx;
} tr[500005];

void insert(string p, int id) {
    int u = 0;
    for (int i = 0; i < p.size(); i++) {
        if (tr[u].child[p[i] - 'a'] == 0) tr[u].child[p[i] - 'a'] = ++cnt;
        u = tr[u].child[p[i] - 'a'];
    }
    tr[u].idx.push_back(id);
}

void buildFailureLinks() {
    queue<int> q;
    int u = 0;
    tr[0].fail = 0;
    for (int i = 0; i < 26; i++) {
        if (tr[u].child[i])
            tr[tr[u].child[i]].fail = u, q.push(tr[u].child[i]);
        else
            tr[u].child[i] = 0;
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u].child[i])
                tr[tr[u].child[i]].fail = tr[tr[u].fail].child[i], q.push(tr[u].child[i]);
            else
                tr[u].child[i] = tr[tr[u].fail].child[i];
        }
    }
}

void query(string s) {
    vector<int> uniqueAns(uniquePatterns.size(), -1);
    for (int i = 0, u = 0; i < s.size(); i++) {
        u = tr[u].child[s[i] - 'a'];
        int v = u;
        while (v) {
            for (int id : tr[v].idx) {
                if (uniqueAns[id] == -1) {
                    uniqueAns[id] = i - uniquePatterns[id].size() + 2;  // 1-indexed position
                }
            }
            v = tr[v].fail;
        }
    }

    // Map back to original indices
    for (int i = 0; i < uniquePatterns.size(); i++) {
        if (uniqueAns[i] != -1) {
            for (int originalId : patternMap[uniquePatterns[i]]) {
                ans[originalId] = uniqueAns[i];
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    fill(ans, ans + n, -1);

    vector<string> patterns(n);
    int maxLen = 0;

    // Read patterns and find max length
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
        maxLen = max(maxLen, (int)patterns[i].size());
    }

    // Use simple approach for very long patterns or highly repetitive cases
    if (maxLen > 10000 || (n == 1 && maxLen > 1000)) {
        for (int i = 0; i < n; i++) {
            size_t pos = s.find(patterns[i]);
            if (pos != string::npos) {
                ans[i] = pos + 1;  // 1-indexed
            }
        }
    } else {
        // Use AC automaton for normal cases
        // Deduplicate patterns
        for (int i = 0; i < n; i++) {
            patternMap[patterns[i]].push_back(i);
        }

        // Create unique patterns list
        for (auto& pair : patternMap) {
            uniquePatterns.push_back(pair.first);
        }

        // Insert only unique patterns
        for (int i = 0; i < uniquePatterns.size(); i++) {
            insert(uniquePatterns[i], i);
        }

        buildFailureLinks();
        query(s);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}