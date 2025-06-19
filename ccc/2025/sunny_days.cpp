#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveS(const string& str) {
    int n = str.length();
    int maxLength = 0;
    int l = 0;
    int cnt = 0;

    for (int r = 0; r < n; r++) {
        if (str[r] == 'P') {
            cnt++;
        }

        // If we have more than 1 'P' in our window, shrink from left
        while (cnt > 1) {
            if (str[l] == 'P') {
                cnt--;
            }
            l++;
        }

        // Update max length (current window has at most 1 'P')
        maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string s;
    string days;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        days += s;
    }

    int maxLen = longestConsecutiveS(days);

    // if string contains only Ss
    if (days.find('P') == string::npos) {
        maxLen -= 1;
    }

    cout << maxLen << '\n';
    return 0;
}
