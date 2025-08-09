// https://leetcode.cn/problems/shortest-path-to-get-all-keys/description/

class Solution {
   private:
    vector<vector<vector<int>>> visited;
    queue<tuple<int, int, int>> pq;
    int n, m, key;

   private:
    void build(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
        key = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    pq.push({i, j, 0});
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    key |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        visited.resize(n, vector<vector<int>>(m, vector<int>(1 << 6, false)));
    }

   public:
    int shortestPathAllKeys(vector<string>& grid) {
        build(grid);
        int level = 0;
        int moves[] = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, k] = pq.front();
                pq.pop();

                if (k == key) {
                    return level;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + moves[dir], ny = y + moves[dir + 1];
                    int newK = k;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
                        continue;
                    }

                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' &&
                        ((newK & (1 << (grid[nx][ny] - 'A'))) == 0)) {
                        continue;
                    }

                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') {
                        newK |= (1 << (grid[nx][ny] - 'a'));
                    }

                    if (!visited[nx][ny][newK]) {
                        visited[nx][ny][newK] = true;
                        pq.push({nx, ny, newK});
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
