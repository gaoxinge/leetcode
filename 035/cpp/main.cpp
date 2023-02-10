class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = -1;
        int j = nums.size();
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            if (nums[k] < target) {
                i = k;
            } else {
                j = k;
            }
        }
        return i + 1;
    }
};
