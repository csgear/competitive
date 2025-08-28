// https://usaco.org/index.php?page=viewproblem2&cpid=644
// USACO 2016 US Open Contest, Silver
// Problem 3. Closing the Farm

#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int parent[N];
bool open[N];
int cnt;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        parent[pu] = pv;
        cnt--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }

    vector<string> answers;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    cnt = 0;

    for (int step = n - 1; step >= 0; step--) {
        int barn = order[step];
        open[barn] = true;
        cnt++;

        for (int neighbor : adj[barn]) {
            if (open[neighbor]) {
                merge(barn, neighbor);
            }
        }

        answers.push_back(cnt == 1 ? "YES" : "NO");
    }

    reverse(answers.begin(), answers.end());

    for (const string& ans : answers) {
        cout << ans << "\n";
    }

    return 0;
}