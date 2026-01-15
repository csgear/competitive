#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e5 + 5) * 3;
int T, K, N;

char S[MAXN];
int ans[MAXN];

void solve() {
    cin >> N >> (S + 1);
    if (N % 2) {
        cout << -1 << "\n";
        return;
    } else if (string(S + 1, S + 1 + N * 3 / 2) == string(S + 1 + N * 3 / 2, S + 1 + N * 3)) {
        cout << 1 << endl;
        for (int i = 1; i < N * 3; i++) {
            cout << 1 << " ";
        }
        cout << 1 << endl;
    } else {
        for (int i = 0; i < N * 3 / 2; i += 3, j += 3) {
            if (S[i + 1] == S[j + 1]) {
                ans[i + 1] = ans[j + 1] = ans[i + 2] = ans[j + 2] = ans[i + 3] = ans[j + 3] = 1;
            } else if (S[i + 1] == S[j + 2]) {
                ans[i + 1] = ans[j + 2] = ans[i + 2] = ans[j + 3] = 1;
                ans[i + 3] = ans[j + 1] = 2;
            } else {
                ans[i + 1] = ans[j + 3] = ans[i + 2] = ans[j + 2] = 1;
                ans[i + 3] = ans[j + 1] = 2;
            }
        }
    }
    cout << *max_element(ans + 1, ans + 1 + N * 3) << "\n";
    for (int i = 1; i < N * 3; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[N * 3] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T >> K;

    while (T--) {
        solve();
    }

    return 0;
}