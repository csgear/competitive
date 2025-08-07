// https://cses.fi/problemset/task/1732

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nxt(n, 0);

    nxt[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = nxt[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }

    vector<int> borders;
    int j = nxt[n - 1];
    while (j >= 0) {
        borders.push_back(j + 1);
        j = nxt[j];
    }

    for (int i = borders.size() - 1; i >= 0; i--) {
        cout << borders[i] << " ";
    }
    cout << endl;

    return 0;
}