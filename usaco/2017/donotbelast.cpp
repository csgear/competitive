// Don't Be Last!【USACO 2017 January Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<string, int> milks;
    string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

    for (int i = 0; i < 7; i++) milks[cows[i]] = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string cow;
        int m;
        cin >> cow >> m;
        milks[cow] += m;
    }

    vector<int> values;
    for (const auto& p : milks) values.push_back(p.second);
    sort(values.begin(), values.end());

    int second = values[0];
    for (int v : values) {
        if (v > values[0]) {
            second = v;
            break;
        }
    }

    // Count cows with second lowest value
    int count = 0;
    string result;
    for (const auto& p : milks) {
        if (p.second == second) {
            count++;
            result = p.first;
        }
    }

    cout << (count == 1 ? result : "Tie") << endl;
    return 0;
}