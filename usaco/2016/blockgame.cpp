// Block Game【USACO 2016 December Contest, Bronze】

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt[26] = {0};

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int freq1[26] = {0}, freq2[26] = {0};

        for (char c : s1) freq1[c - 'a']++;
        for (char c : s2) freq2[c - 'a']++;

        for (int j = 0; j < 26; j++) {
            cnt[j] += max(freq1[j], freq2[j]);
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}