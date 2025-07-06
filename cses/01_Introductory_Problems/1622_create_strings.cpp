// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    do {
        cnt++;
    } while (next_permutation(s.begin(), s.end()));

    cout << cnt << endl;

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}