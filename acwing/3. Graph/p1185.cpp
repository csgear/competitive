// https://www.acwing.com/problem/content/1187/
// 1185. 单词游戏

#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int n;
int din[N], dout[N];
bool used[N];
int fa[N];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(used, 0, sizeof used);

        for (int i = 0; i < N; i++) fa[i] = i;

        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int u = s.front() - 'a';
            int v = s.back() - 'a';
            dout[u]++;
            din[v]++;
            used[u] = used[v] = true;
            fa[find(u)] = find(v);
        }

        int start = 0, end = 0;
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (din[i] == dout[i])
                continue;
            else if (dout[i] - din[i] == 1)
                start++;
            else if (din[i] - dout[i] == 1)
                end++;
            else {
                possible = false;
                break;
            }
        }

        possible = possible && ((start == 0 && end == 0) || (start == 1 && end == 1));

        if (possible) {
            int rep = -1;
            for (int i = 0; i < 26; i++) {
                if (used[i]) {
                    if (rep == -1)
                        rep = find(i);
                    else if (find(i) != rep) {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (possible)
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
    }

    return 0;
}