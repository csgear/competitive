// https://cses.fi/problemset/task/1660

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach O(n²)
int solveBruteForce(vector<int>& a, int x) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == x) {
                ans++;
            }
        }
    }
    return ans;
}
// works for positive numbers
int solveSlidingWindow(vector<int>& a, int x) {
    int n = a.size();
    int ans = 0;
    int sum = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > x && left < right) {
            sum -= a[left];
            left++;
        }
        if (sum == x) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solveSlidingWindow(a, x) << endl;
    return 0;
}
