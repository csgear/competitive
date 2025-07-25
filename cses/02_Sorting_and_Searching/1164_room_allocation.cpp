// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }

    sort(customers.begin(), customers.end());

    // Priority queue to manage rooms based on departure time and room number
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> rooms(n);
    int next_room = 1;

    for (const auto& customer : customers) {
        int arrival = customer[0];
        int departure = customer[1];
        int index = customer[2];

        if (!pq.empty() && pq.top().first < arrival) {
            int room = pq.top().second;
            pq.pop();
            rooms[index] = room;
            pq.push({departure, room});
        } else {
            rooms[index] = next_room;
            pq.push({departure, next_room});
            next_room++;
        }
    }

    cout << next_room - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rooms[i];
        if (i < n - 1) cout << ' ';
    }
    cout << '\n';

    return 0;
}