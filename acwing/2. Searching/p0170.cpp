// https://www.acwing.com/problem/content/172/

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int path[N];

int n;

bool dfs(int u, int depth) {
    if (u == depth) return path[u - 1] == n;

    bool visited[N] = {false};

    for (int i = u - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int x = path[j] + path[i];
            if (x > path[u - 1] && x <= n && !visited[x]) {
                visited[x] = true;
                path[u] = x;
                if (dfs(u + 1, depth)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    while (cin >> n, n) {
        int depth = 1;
        path[0] = 1;
        while (dfs(1, depth) == false) depth++;
        for (int i = 0; i < depth; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}