// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

#define ll long long

const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;

int head[MAXN], to[MAXM], nxt[MAXM], cnt;
ll w[MAXM];
int n, m;

void add_edge(int u, int v, int weight) {
  nxt[cnt] = head[u];
  to[cnt] = v;
  w[cnt] = weight;
  head[u] = cnt;
  cnt++;
}

int main() {
  fastio;
  cin >> n >> m;

  cnt = 1;
  memset(head, -1, sizeof(head));

  for (int i = 1; i <= m; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    add_edge(u, v, weight);
  }

  vector<long long> dist(n + 1, LLONG_MAX);

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) {
      continue;
    }

    for (int e = head[u]; e != -1; e = nxt[e]) {
      int v = to[e];
      ll weight = w[e];
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << dist[i] << " ";
  }
  cout << endl;
}