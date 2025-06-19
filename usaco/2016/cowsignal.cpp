// The Cow-Signal【USACO 2016 December Contest, Bronze】

#include <bits/stdc++.h>

using namespace std;

void print_grid(string s, int k) {
    for (int i = 0; i < k; i++) {
        for (char c : s) {
            for (int j = 0; j < k; j++) {
                cout << c;
            }
        }
        cout << endl;
    }
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        print_grid(s, k);
    }
    return 0;
}