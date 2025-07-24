// https://dmoj.ca/problem/ccc05j1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, e, w;
    cin >> d >> e >> w;
    double costA = d >= 100 ? (d - 100) * 0.25 : 0;
    costA += e * 0.15 + w * 0.20;
    double costB = d >= 250 ? (d - 250) * 0.45 : 0;
    costB += e * 0.35 + w * 0.25;
    cout << "Plan A costs " << costA << endl;
    cout << "Plan B costs " << costB << endl;

    if (abs(costA - costB) < 1e-9) {
        cout << "Plan A and B are the same price." << endl;
    } else {
        cout << (costA < costB ? "Plan A is cheapest." : "Plan B is cheapest.") << endl;
    }
}