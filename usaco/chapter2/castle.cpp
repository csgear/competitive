/*
ID: juniory1
LANG: C++
TASK: castle
*/

#include <bits/stdc++.h>

using namespace std;

// Directions: West, North, East, South
// dx == rows
int dx[] = {0, -1, 0, 1};
// dy = columns
int dy[] = {-1, 0, 1, 0};
int wall[] = {1, 2, 4, 8};

int N, M;  // N = rows, M = columns
vector<vector<int>> grid;
vector<vector<int>> room_id;
vector<int> room_size;

int bfs(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    room_id[x][y] = id;
    int size = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // If no wall in this direction
                if ((grid[cx][cy] & wall[dir]) == 0 && room_id[nx][ny] == 0) {
                    room_id[nx][ny] = id;
                    q.push({nx, ny});
                    size++;
                }
            }
        }
    }
    return size;
}

int main() {
    freopen("castle.in", "r", stdin);

    freopen("castle.out", "w", stdout);
    // M == columns & N == rows
    cin >> M >> N;
    grid.assign(N, vector<int>(M));
    room_id.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;
    int largest_room = 0;

    // Find all rooms
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (room_id[i][j] == 0) {
                rooms++;
                int size = bfs(i, j, rooms);
                room_size.push_back(size);
                largest_room = max(largest_room, size);
            }
        }
    }

    int best_size = 0;
    int best_row = 0, best_col = 0;
    char best_dir = 'N';

    // Try removing one wall
    for (int j = 0; j < M; j++) {           // Columns left to right
        for (int i = N - 1; i >= 0; i--) {  // Rows bottom to top
            // Check North wall
            if (i > 0 && room_id[i][j] != room_id[i - 1][j]) {
                int combined = room_size[room_id[i][j] - 1] + room_size[room_id[i - 1][j] - 1];
                if (combined > best_size ||
                    (combined == best_size && (j < best_col || (j == best_col && i > best_row)))) {
                    best_size = combined;
                    best_row = i;
                    best_col = j;
                    best_dir = 'N';
                }
            }
            // Check East wall
            if (j < M - 1 && room_id[i][j] != room_id[i][j + 1]) {
                int combined = room_size[room_id[i][j] - 1] + room_size[room_id[i][j + 1] - 1];
                if (combined > best_size ||
                    (combined == best_size && (j < best_col || (j == best_col && i > best_row)))) {
                    best_size = combined;
                    best_row = i;
                    best_col = j;
                    best_dir = 'E';
                }
            }
        }
    }

    cout << rooms << endl;
    cout << largest_room << endl;
    cout << best_size << endl;
    cout << best_row + 1 << " " << best_col + 1 << " " << best_dir << endl;

    return 0;
}
