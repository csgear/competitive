// https://cses.fi/problemset/task/1161/
// Greedy + Min-Heap (Priority Queue)
// Similar to Huffman Coding

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, n;
    cin >> x >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        pq.push(len);
    }

    ll totalCost = 0;

    while (pq.size() > 1) {
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();

        ll merged = first + second;
        totalCost += merged;

        pq.push(merged);
    }

    cout << totalCost << endl;

    return 0;
}