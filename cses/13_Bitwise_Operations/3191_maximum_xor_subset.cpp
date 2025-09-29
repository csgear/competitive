// https://cses.fi/problemset/task/3191

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e5 + 5;
const int LOG_X = 31;
int a[N];

int n;

int maxSubsetXOR() {
    int index = 1;
    for (int i = LOG_X - 1; i >= 0; i--) {
        int maxInd = index;
        int maxEle = INT_MIN;
        for (int j = index; j <= n; j++) {
            if ((a[j] & (1 << i)) != 0 && a[j] > maxEle) {
                maxEle = a[j];
                maxInd = j;
            }
        }
        if (maxEle == INT_MIN) continue;
        swap(a[maxInd], a[index]);
        for (int j = 1; j <= n; j++) {
            if (j != index && (a[j] & (1 << i)) != 0) {
                a[j] ^= a[index];
            }
        }
        index++;
    }
    int result = 0;
    for (int i = 1; i <= index; i++) {
        result ^= a[i];
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << maxSubsetXOR() << endl;
    return 0;
}
