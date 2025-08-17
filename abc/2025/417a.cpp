// https://atcoder.jp/contests/abc417/tasks/abc417_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    string ans = S.substr(A, N - A - B);

    cout << ans << endl;
    return 0;
}