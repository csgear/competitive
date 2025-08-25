// Angry Cows【USACO 2016 January Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;

int count_explosion(int s, int dir) {
    int radius = 1;
    int prev = s;
    while (true) {
        int next = prev;
        while (next + dir >= 0 && next + dir < n && abs(x[next + dir] - x[prev]) <= radius) {
            next += dir;
        }
        if (next == prev) {
            break;
        }
        prev = next;
        radius++;
    }

    return abs(prev - s);
}

int main() {
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, count_explosion(i, -1) + count_explosion(i, 1) + 1);
    }

    cout << ans << endl;
}