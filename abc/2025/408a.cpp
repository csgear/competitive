// https://atcoder.jp/contests/abc408/tasks/abc408_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int S;
    cin >> N >> S;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int last_tap = 0.0;
    bool awake = true;
    for (int i = 0; i < N; ++i) {
        if (T[i] - last_tap >= S + 0.5) {
            awake = false;
            break;
        }
        last_tap = T[i];
    }

    cout << (awake ? "Yes" : "No") << endl;
    return 0;
}
