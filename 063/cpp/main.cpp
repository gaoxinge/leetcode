class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long> cache(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> gs = obstacleGrid[m - 1 - i];
            for (int j = 0; j < n; j++) {
                int g = gs[n - 1 - j];
                if (g == 1) {
                    cache[j] = 0;
                } else if (i == 0 && j == 0) {
                    cache[j] = 1;
                } else if (j == 0) {
                    cache[j] = cache[j];
                } else {
                    cache[j] += cache[j - 1];
                }
            }
        }
        return cache[n - 1];
    }
};
