// Mowing the Field【USACO 2016 January Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<array<int, 2>, int> visited;
    int ans = INT_MAX;
    int tick = 1;
    int x = 0, y = 0;
    visited[{0, 0}] = tick++;
    for (int i = 0; i < N; i++) {
        string move;
        int step;
        cin >> move >> step;
        int xdir = 0, ydir = 0;
        if (move == "N") {
            ydir = 1;
        } else if (move == "S") {
            ydir = -1;
        } else if (move == "E") {
            xdir = 1;
        } else if (move == "W") {
            xdir = -1;
        }
        for (int j = 0; j < step; j++) {
            x += xdir;
            y += ydir;
            tick++;
            if (visited[{x, y}]) {
                // cout << "visited at " << x << " " << y << " at tick " << tick << endl;
                ans = min(ans, tick - visited[{x, y}]);
            }
            visited[{x, y}] = tick;
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}