// Promotion Counting 【USACO 2016 February Contest, Bronze】

#include <bits/stdc++.h>

using namespace std;

int main() {
    int d[4][2];

    for (int i = 0; i < 4; i++) {
        cin >> d[i][0] >> d[i][1];
    }

    int ans[4] = {0};

    ans[3] = d[3][1] - d[3][0];
    ans[2] = d[2][1] - d[2][0] + ans[3];
    ans[1] = d[1][1] - d[1][0] + ans[2];

    cout << ans[1] << endl;
    cout << ans[2] << endl;
    cout << ans[3] << endl;

    return 0;
}
