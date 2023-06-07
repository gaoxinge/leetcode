class Solution {
public:
    int trap(vector<int>& height) {
        int i = 1;
        int j = height.size() - 2;
        int maxLeft = height[0];
        int maxRight = height[height.size() - 1];
        int n = 0;
        while (i <= j) {
            if (maxLeft <= maxRight) {
                if (maxLeft > height[i]) {
                    n += maxLeft - height[i];
                }
                maxLeft = max(maxLeft, height[i]);
                i++;
            } else {
                if (maxRight > height[j]) {
                    n += maxRight - height[j];
                }
                maxRight = max(maxRight, height[j]);
                j--;
            }
        }
        return n;
    }
};
