// P30215-Speeding Ticket【USACO 2015 December Contest, Bronze】

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> s1(N + 1), limit(N + 1);
    vector<int> s2(M + 1), speed(M + 1);

    s1[0] = s2[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> s1[i] >> limit[i];
        s1[i] += s1[i - 1];
    }

    for (int i = 1; i <= M; i++) {
        cin >> s2[i] >> speed[i];
        s2[i] += s2[i - 1];
    }

    int max_speeding = 0;

    int p1 = 1, p2 = 1;

    while (p1 <= N && p2 <= M) {
        max_speeding = max(max_speeding, speed[p2] - limit[p1]);

        if (s1[p1] == s2[p2]) {
            p1++;
            p2++;
        }

        while (s1[p1] > s2[p2]) {
            p2++;
            max_speeding = max(max_speeding, speed[p2] - limit[p1]);
        }

        while (s1[p1] < s2[p2]) {
            p1++;
            max_speeding = max(max_speeding, speed[p2] - limit[p1]);
        }
    }

    cout << max_speeding << endl;

    return 0;
}