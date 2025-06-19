#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    // vertex label 1~N
    vector<int> degree(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int from, to;
        cin >> from >> to;
        degree[from]++;
        degree[to++];
    }

    int max_degree = 0;

    for (int i = 1; i <= N; i++) {
        max_degree = max(max_degree, degree[i]);
    }

    cout << max_degree << endl;

    return 0;
}