// https://cses.fi/problemset/task/1111

#include <bits/stdc++.h>
using namespace std;

string manacher(string s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    int maxLen = 0, maxCenter = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }

    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << manacher(s) << endl;
    return 0;
}
