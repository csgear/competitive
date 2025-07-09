// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            left++;
            right--;
        } else {
            right--;
        }
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}