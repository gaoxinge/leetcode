class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int n = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                maxLeft = max(maxLeft, height[i]);
                n += maxLeft - height[i];
                i++;
            } else {
                maxRight = max(maxRight, height[j]);
                n += maxRight - height[j];
                j--;
            }
        }
        return n;
    }
};
