// https://www.acwing.com/problem/content/description/94/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

void calc(int x) {
    if (x == n + 1) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    // Don't include x
    calc(x + 1);

    // Include x
    ans.push_back(x);
    calc(x + 1);
    ans.pop_back();
}

int main() {
    cin >> n;
    calc(1);
}