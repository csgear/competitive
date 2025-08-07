// https://cses.fi/problemset/task/2103

#include <bits/stdc++.h>
using namespace std;

string s;
int n, cnt = 0, ans[500005];

vector<int> adj[500005];

struct Node {
    int fail, child[26] = {}, occ = 0;
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
    for (int i = 1; i <= cnt; i++) adj[tr[i].fail].push_back(i);
}

void query(string s) {
    for (int i = 0, u = 0; i < s.size(); i++) {
        u = tr[u].child[s[i] - 'a'];
        tr[u].occ++;
    }
}

int dfs(int u) {
    int tot = tr[u].occ;

    for (int v : adj[u]) tot += dfs(v);

    for (int id : tr[u].idx) ans[id] = tot;

    return tot;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string p;
        cin >> p;
        insert(p, i);
    }

    buildFailureLinks();

    query(s);

    dfs(0);

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}