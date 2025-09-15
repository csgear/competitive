// https://usaco.org/index.php?page=viewproblem2&cpid=1060
// USACO 2020 December Contest, Bronze
// Problem 2. Daisy Chains

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + p[i];
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        unordered_map<int, int> freq;
        for (int j = i; j <= n; j++) {
            freq[p[j]]++;

            int sum = prefix[j] - prefix[i - 1];
            int length = j - i + 1;

            if (sum % length == 0) {
                int avg = sum / length;
                if (freq.count(avg) > 0) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}