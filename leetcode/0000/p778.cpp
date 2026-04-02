// https://leetcode.cn/problems/swim-in-rising-water/description/

class Solution {
    template <typename T>
    using MinPQ = priority_queue<T, vector<T>, greater<T>>;

   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int moves[] = {0, 1, 0, -1, 0};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        MinPQ<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return time;

            for (int i = 0; i < 4; i++) {
                int nx = x + moves[i], ny = y + moves[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newTime = max(time, grid[nx][ny]);
                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};