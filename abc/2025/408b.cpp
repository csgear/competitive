// https://atcoder.jp/contests/abc408/tasks/abc408_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << a.size() << endl;
    vector<int> result;
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            result.push_back(a[i]);
        }
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}