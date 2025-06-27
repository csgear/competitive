#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n = 0;
int a[MAXN];
int f[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> a[++n]);
    --n;

    // First DP: Longest non-increasing subsequence
    int length = 0;
    fill(f, f + MAXN, 0);
    f[0] = INF;
    for (int i = 1; i <= n; ++i) {
        int left = 0, right = length + 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (f[mid] >= a[i])
                left = mid;
            else
                right = mid;
        }
        int pos = left + 1;
        if (pos > length) length = pos;
        f[pos] = a[i];
    }
    cout << length << '\n';

    // Second DP: Longest increasing subsequence
    length = 0;
    fill(f, f + MAXN, 0);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int left = 0, right = length + 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (f[mid] < a[i])
                left = mid;
            else
                right = mid;
        }
        int pos = left + 1;
        if (pos > length) length = pos;
        f[pos] = a[i];
    }
    cout << length << '\n';

    return 0;
}