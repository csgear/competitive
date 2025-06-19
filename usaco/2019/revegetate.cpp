#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXM = 305;

int head[MAXN];
int nextEdge[MAXM];
int to[MAXM];
int cnt = 1;

int grass[MAXN];

void addEdge(int u, int v) {
    nextEdge[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

int main() {
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        addEdge(u, v);
        addEdge(v, u);
    }

    for (int u = 1; u <= N; u++) {
        bool used[5] = {false};
        for (int i = head[u]; i > 0; i = nextEdge[i]) {
            int v = to[i];
            if (grass[v]) {
                used[grass[v]] = true;
            }
        }

        for (int c = 1; c <= 4; ++c) {
            if (!used[c]) {
                grass[u] = c;
                break;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << grass[i];
    }

    cout << endl;
}
