class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> s;
        int m = 0;
        for (int i = 0; i < heights.size(); ) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            } else {
                int j = s.top();
                s.pop();
                int t = heights[j] * (s.empty() ? i : i - s.top() - 1);
                m = std::max(m, t);
            }
        }
        while (!s.empty()) {
            int j = s.top();
            s.pop();
            int t = heights[j] * (s.empty() ? heights.size() : heights.size() - s.top() - 1);
            m = std::max(m, t);
        }
        return m;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> t(matrix[0].size(), 0);
        vector<vector<int>> heightss(matrix.size(), t);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                heightss[i][j] = matrix[i][j] == '1' ? 1 : 0;
                if (i > 0 && heightss[i][j] == 1) {
                    heightss[i][j] += heightss[i - 1][j];
                }
            }
        }
        
        int m = 0;
        for (auto &heights: heightss) {
            m = std::max(m, largestRectangleArea(heights));
        }
        return m;
    }
};
