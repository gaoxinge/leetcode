class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int m = 0;
        while (i < j) {
            int m0 = (j - i) * std::min(height[i], height[j]);
            m = std::max(m, m0);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return m;
    }
};
