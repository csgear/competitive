// https://cses.fi/problemset/task/1092
// Two Sets

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll total_sum = n * (n + 1) / 2;

    if (total_sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    ll target = total_sum / 2;

    vector<int> set1, set2;
    ll current_sum = 0;

    // greedy approach
    for (int i = n; i >= 1; i--) {
        if (current_sum + i <= target) {
            set1.push_back(i);
            current_sum += i;
        } else {
            set2.push_back(i);
        }
    }

    // Output result
    cout << "YES\n";

    // Output first set
    cout << set1.size() << "\n";
    for (int i = 0; i < set1.size(); i++) {
        cout << set1[i];
        if (i < set1.size() - 1) cout << " ";
    }
    cout << "\n";

    // Output second set
    cout << set2.size() << "\n";
    for (int i = 0; i < set2.size(); i++) {
        cout << set2[i];
        if (i < set2.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
