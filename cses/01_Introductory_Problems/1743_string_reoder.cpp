// https://cses.fi/problemset/task/1743

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int freq[26];
char input[MAXN];
char result[MAXN];

bool isPlacementPossible(int currentChar) {
    int maxFreqChar = -1;
    int totalRemaining = 0;

    for (int i = 0; i < 26; ++i) {
        if (maxFreqChar == -1 || freq[i] > freq[maxFreqChar]) {
            maxFreqChar = i;
        }
        totalRemaining += freq[i];
    }

    if (freq[maxFreqChar] > (totalRemaining + 1) / 2) return false;

    // the current character cannot be placed if it exceeds half of the remaining characters
    if (freq[currentChar] > totalRemaining / 2) return false;

    return true;
}

int main() {
    cin >> input;

    int N = strlen(input);

    for (int i = 0; i < N; ++i) {
        freq[input[i] - 'A']++;
    }

    int lastChar = -1;

    for (int i = 0; i < N; ++i) {
        bool filled = false;

        for (int c = 0; c < 26; ++c) {
            if (freq[c] == 0) continue;
            if (c == lastChar) continue;

            freq[c]--;

            if (isPlacementPossible(c)) {
                result[i] = (char)(c + 'A');
                lastChar = c;
                filled = true;
                break;
            } else {
                freq[c]++;
            }
        }

        if (!filled) {
            cout << "-1" << endl;
            return 0;
        }
    }

    result[N] = '\0';
    cout << result << endl;
    return 0;
}
