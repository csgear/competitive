// https://atcoder.jp/contests/abc418/tasks/abc418_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    double ans = 0.0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 't') continue;
        int cnt = 1;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == 't') cnt++;

            if (j < i + 2 || s[j] != 't') continue;

            ans = max(ans, 1.0 * (cnt - 2) / (j - i - 1.0));
        }
    }

    printf("%.12f\n", ans);

    return 0;
}
