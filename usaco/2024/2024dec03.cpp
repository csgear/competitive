// It's Mooin' Time【 USACO 2024 December Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 20000 + 20;
char a[N];
int n, f;
vector<string> ans;
int vis[N];

int main() {
    fastio;
    scanf("%d%d", &n, &f);
    scanf("%s", a + 1);

    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == j) continue;
            int cnt = 0;
            memset(vis, 0, sizeof(vis));
            for (int k = 1; k <= n - 2; k++) {
                if (a[k] == i && a[k + 1] == j && a[k + 2] == j) {
                    cnt++;
                    vis[k] = 1;
                    vis[k + 1] = 1;
                    vis[k + 2] = 1;
                }
            }
            if (cnt >= f) {
                ans.push_back({i, j, j});
            } else if (cnt == f - 1) {
                for (int k = 1; k <= n - 2; k++) {
                    if (a[k] == i && a[k + 1] == j && vis[k + 2] == 0) {
                        ans.push_back({i, j, j});
                        break;
                    }
                    if (vis[k] == 0 && a[k + 1] == j && a[k + 2] == j) {
                        ans.push_back({i, j, j});
                        break;
                    }
                    if (a[k] == i && vis[k + 1] == 0 && a[k + 2] == j) {
                        ans.push_back({i, j, j});
                        break;
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (string p : ans) {
        cout << p << endl;
    }
    return 0;
}
