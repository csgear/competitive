// https://www.luogu.com.cn/problem/P1012

#include <bits/stdc++.h>

using namespace std;

// Custom comparator for sorting strings to form the largest number
bool compare(const string& a, const string& b) { return a + b > b + a; }

int main() {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    // Sort using custom comparator
    sort(a.begin(), a.end(), compare);

    for (string s : a) {
        cout << s;
    }
    cout << endl;
    return 0;
}