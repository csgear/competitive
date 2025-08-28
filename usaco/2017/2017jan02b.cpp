// https://usaco.org/index.php?page=viewproblem2&cpid=688
// USACO 2017 January Contest, Bronze
// Problem 2. Hoof, Paper, Scissors

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> games(n);
    for (int i = 0; i < n; i++) {
        cin >> games[i].first >> games[i].second;
    }

    int maxWins = 0;

    vector<int> assignment = {1, 2, 3};
    do {
        int wins = 0;
        int H = assignment[0], P = assignment[1], S = assignment[2];

        for (auto& [first, second] : games) {
            if ((first == H && second == S) || (first == S && second == P) ||
                (first == P && second == H)) {
                wins++;
            }
        }
        maxWins = max(maxWins, wins);
    } while (next_permutation(assignment.begin(), assignment.end()));

    cout << maxWins << endl;
    return 0;
}