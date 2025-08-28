// https://usaco.org/index.php?page=viewproblem2&cpid=894
// USACO 2019 January Contest, Silver
// Problem 1. Grass Planting

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int max_degree = 0;
    for (int i = 1; i <= n; i++) {
        max_degree = max(max_degree, degree[i]);
    }

    cout << max_degree + 1 << endl;

    return 0;
}