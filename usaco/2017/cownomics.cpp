#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> spotty(N), plain(N);
    for (int i = 0; i < N; i++) cin >> spotty[i];
    for (int i = 0; i < N; i++) cin >> plain[i];

    int count = 0;

    for (int pos = 0; pos < M; pos++) {
        unordered_set<char> s;

        // Record characters at position pos for spotty cows
        for (int i = 0; i < N; i++) {
            s.insert(spotty[i][pos]);
        }

        bool distinguishable = true;

        // Check if plain cows share any character at position pos
        for (int i = 0; i < N; i++) {
            if (s.count(plain[i][pos])) {
                distinguishable = false;
                break;
            }
        }

        if (distinguishable) count++;
    }

    cout << count << endl;

    return 0;
}