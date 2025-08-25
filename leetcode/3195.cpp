// https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/description/

class Solution {
   public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    minx = min(minx, i);
                    miny = min(miny, j);
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                }
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};