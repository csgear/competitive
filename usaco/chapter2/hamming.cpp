/*
ID: juniory1
LANG: C++
TASK: hamming
*/

#include <bits/stdc++.h>

using namespace std;

int N, B, D;

int hammingDistance(int a, int b) {
    int x = a ^ b;
    int count = 0;
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}

bool isValid(int i, const vector<int>& words) {
    for (auto word : words) {
        if (hammingDistance(i, word) < D) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    cin >> N >> B >> D;

    vector<int> words;

    int maxN = 1 << B;

    for (int i = 0; i < maxN && words.size() < N; i++) {
        if (isValid(i, words)) {
            words.push_back(i);
        }
    }

    for (int i = 0; i < words.size(); ++i) {
        cout << words[i];
        if ((i + 1) % 10 == 0 || i == words.size() - 1)
            cout << "\n";
        else
            cout << " ";
    }

    return 0;
}