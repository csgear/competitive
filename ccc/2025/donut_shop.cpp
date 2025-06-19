#include <bits/stdc++.h>

using namespace std;

int main() {
    int D, E, Q;
    string symbol;

    cin >> D >> E;

    int res = D;

    for (int i = 0; i < E; i++) {
        cin >> symbol;
        cin >> Q;
        if (symbol == "+") {
            res += Q;
        }
        if (symbol == "-") {
            res -= Q;
        }
    }
    cout << res << endl;
}