
// contest link: https://dmoj.ca/problem/joi05fp1

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    vector<int> p(M, 0);

    int n;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> n;
            p[j] += n;
        }
    }

    vector<pair<int, int>> p1(M);

    for (int i = 0; i < M; i++) {
        p1.push_back(make_pair(i, p[i]));
    }

    // sort M
    stable_sort(p1.begin(), p1.end(),
                [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
                    if (left.second == right.second) {
                        return left.first < right.first;
                    } else {
                        return left.second > right.second;
                    }
                });

    cout << p1[0].first + 1;

    for (int i = 1; i < M; i++) {
        cout << " " << p1[i].first + 1;
    }
    cout << endl;

    return 0;
}
