// https://www.acwing.com/problem/content/137/

#include <bits/stdc++.h>
using namespace std;

const int N = 300010;

int n, m;
int s[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int res = INT_MIN;
    deque<int> q;
    q.push_back(0);

    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.front() < i - m) {
            q.pop_front();
        }
        res = max(res, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << res << endl;
    return 0;
}