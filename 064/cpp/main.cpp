class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rs(n, -1);
        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                int g = grid[i][j];
                if (rs[j] == -1 && j == n - 1) {
                    rs[j] = g;
                } else if (rs[j] == -1) {
                    rs[j] = rs[j + 1] + g;
                } else if (j == n - 1) {
                    rs[j] += g;
                } else {
                    rs[j] = min(rs[j], rs[j + 1]) + g;
                }
            }
        }
        
        return rs[0];
    }
};
