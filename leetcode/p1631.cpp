// https://leetcode.cn/problems/path-with-minimum-effort/description/

class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int moves[] = {-1, 0, 1, 0, -1};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == m - 1) return effort;
            for (int i = 0; i < 4; i++) {
                int nx = x + moves[i];
                int ny = y + moves[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }
        return 0;
    }
};