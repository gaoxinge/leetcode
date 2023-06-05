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
};
