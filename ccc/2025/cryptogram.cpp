// https://dmoj.ca/problem/ccc25s2
// CCC '25 S2 - Cryptogram Cracking Club

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int c;
    cin >> c;

    vector<pair<char, int>> blocks;
    int i = 0, n = s.size();

    while (i < n) {
        char letter = s[i++];
        int j = i;
        while (j < n && isdigit(s[j])) ++j;
        int count = stoi(s.substr(i, j - i));
        blocks.emplace_back(letter, count);
        i = j;
    }

    int total = 0;
    for (const auto& [_, count] : blocks) total += count;

    c %= total;
    for (const auto& [letter, count] : blocks) {
        if (c < count) {
            cout << letter << '\n';
            break;
        }
        c -= count;
    }
}
