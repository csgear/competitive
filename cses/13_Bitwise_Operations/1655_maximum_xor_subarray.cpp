// https://cses.fi/problemset/task/1655

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LOG_X = 30;
const int MAXN = N * LOG_X;

int trie[MAXN][2];
int nodeCount = 0;

void insert(int num) {
    int curr = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (trie[curr][bit] == 0) {
            trie[curr][bit] = ++nodeCount;
        }
        curr = trie[curr][bit];
    }
}

int getMaxXor(int num) {
    int curr = 0;
    int maxXor = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int oppositeBit = 1 - bit;
        if (trie[curr][oppositeBit] != 0) {
            maxXor |= (1 << i);
            curr = trie[curr][oppositeBit];
        } else {
            curr = trie[curr][bit];
        }
    }
    return maxXor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insert(0);

    int prefixXor = 0;
    int maxXor = 0;

    for (int i = 0; i < n; i++) {
        prefixXor ^= arr[i];
        // Find maximum XOR with any previous prefix
        maxXor = max(maxXor, getMaxXor(prefixXor));
        insert(prefixXor);
    }

    cout << maxXor << endl;
    return 0;
}