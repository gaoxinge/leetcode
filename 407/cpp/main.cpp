class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        auto cmp = [](std::tuple<int, int, int> left, std::tuple<int, int, int> right) {
            return std::get<2>(left) > std::get<2>(right);
        };
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(cmp)> pq(cmp);
        std::vector<std::vector<bool>> v(m, std::vector<bool>(n, 0));

        for (int i = 0; i < m; i++) {
            pq.push({i, 0, heightMap[i][0]});
            v[i][0] = true;
            pq.push({i, n - 1, heightMap[i][n - 1]});
            v[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({0, j, heightMap[0][j]});
            v[0][j] = true;
            pq.push({m - 1, j, heightMap[m - 1][j]});
            v[m - 1][j] = true;
        }

        int r = 0;
        std::vector<std::tuple<int, int>> ds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            for (auto &d: ds) {
                int x = std::get<0>(e) + std::get<0>(d);
                int y = std::get<1>(e) + std::get<1>(d);
                if (x > -1 && x < m && y > -1 && y < n && !(v[x][y])) {
                    int h = std::max(std::get<2>(e), heightMap[x][y]);
                    r += h - heightMap[x][y];
                    pq.push({x, y, h});
                    v[x][y] = true;
                }
            }
        }

        return r;
    }
};
