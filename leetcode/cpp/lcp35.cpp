// https://leetcode.cn/problems/DFPeFJ/description/

class Solution {
   public:
    template <typename T>
    using MinPQ = priority_queue<T, vector<T>, greater<T>>;

    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end,
                        vector<int>& charge) {
        int n = charge.size();
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& path : paths) {
            int u = path[0], v = path[1], w = path[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<vector<int>> dist(n, vector<int>(cnt + 1, INT_MAX));

        dist[start][0] = 0;

        vector<vector<bool>> visited(n, vector<bool>(cnt + 1, false));

        MinPQ<tuple<int, int, int>> pq;

        pq.push({0, start, 0});  // {cost, cur, power}

        while (!pq.empty()) {
            auto [cost, cur, power] = pq.top();
            pq.pop();
            if (visited[cur][power]) continue;

            if (cur == end) return cost;

            visited[cur][power] = true;

            if (power < cnt) {
                if (!visited[cur][power + 1] && cost + charge[cur] < dist[cur][power + 1]) {
                    dist[cur][power + 1] = cost + charge[cur];
                    pq.push({dist[cur][power + 1], cur, power + 1});
                }
            }

            for (auto& edge : graph[cur]) {
                int nextCity = edge.first;
                int restPower = power - edge.second;
                int nextCost = cost + edge.second;
                if (restPower >= 0 && !visited[nextCity][restPower] &&
                    nextCost < dist[nextCity][restPower]) {
                    dist[nextCity][restPower] = nextCost;
                    pq.push({nextCost, nextCity, restPower});
                }
            }
        }
        return -1;
    }
};