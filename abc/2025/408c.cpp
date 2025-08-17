// https://atcoder.jp/contests/abc408/tasks/abc408_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cover(N + 2, 0);

    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        cover[L]++;
        cover[R + 1]--;
    }

    int min_cover = 1e9;
    int current = 0;
    for (int i = 1; i <= N; ++i) {
        current += cover[i];
        min_cover = min(min_cover, current);
    }
    cout << min_cover << endl;
    return 0;
}