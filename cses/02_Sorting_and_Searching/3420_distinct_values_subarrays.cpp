// https://cses.fi/problemset/task/3420

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    unordered_map<int, int> last_pos;

    for (int r = 0, l = 0; r < n; r++) {
        int x;
        cin >> x;

        // last_pos[x] >= l make sure last_pos[x] is within
        // the current subarray [l, r]
        if (last_pos.count(x) && last_pos[x] >= l) {
            l = last_pos[x] + 1;
        }
        last_pos[x] = r;

        ans += r - l + 1;
    }

    cout << ans << endl;
    return 0;
}