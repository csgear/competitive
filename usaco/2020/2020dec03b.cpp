// https://usaco.org/index.php?page=viewproblem2&cpid=1061
// USACO 2020 December Contest, Bronze
// Problem 3. Stuck in a Rut

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> east, north;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir >> x[i] >> y[i];
        if (dir == 'E') {
            east.push_back(i);
        } else {
            north.push_back(i);
        }
    }

    sort(east.begin(), east.end(), [&](int a, int b) { return y[a] < y[b]; });

    sort(north.begin(), north.end(), [&](int a, int b) { return x[a] < x[b]; });

    vector<bool> stop(n, false);
    vector<int> grass(n, 0);

    for (int j : east) {
        for (int k : north) {
            if (!stop[j] && !stop[k] && x[k] > x[j] && y[j] > y[k]) {
                int distEast = x[k] - x[j];
                int distNorth = y[j] - y[k];

                if (distEast > distNorth) {
                    stop[j] = true;
                    grass[j] = distEast;
                } else if (distNorth > distEast) {
                    stop[k] = true;
                    grass[k] = distNorth;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (stop[i]) {
            cout << grass[i] << "\n";
        } else {
            cout << "Infinity\n";
        }
    }

    return 0;
}
