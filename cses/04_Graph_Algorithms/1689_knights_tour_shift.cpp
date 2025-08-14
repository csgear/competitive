#include <bits/stdc++.h>
using namespace std;

const int N = 8;

vector<vector<int>> grid = {{1, 62, 59, 42, 37, 46, 49, 44}, {60, 41, 64, 53, 58, 43, 36, 47},
                            {63, 2, 61, 38, 23, 48, 45, 50}, {40, 19, 54, 57, 52, 7, 24, 35},
                            {3, 56, 39, 20, 25, 22, 51, 8},  {18, 13, 16, 55, 6, 29, 34, 31},
                            {15, 4, 11, 26, 21, 32, 9, 28},  {12, 17, 14, 5, 10, 27, 30, 33}};

int main() {
    int x, y;
    cin >> x >> y;

    int shift = grid[y - 1][x - 1] - 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int step = grid[i][j] - shift;
            if (step <= 0) step += N * N;
            cout << step << " ";
        }
        cout << "\n";
    }
}