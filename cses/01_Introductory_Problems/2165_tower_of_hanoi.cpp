// https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}