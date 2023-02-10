class Solution {
public:
    int searchRange1(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        if (nums[nums.size() - 1] < target) {
            return nums.size() - 1;
        }
        int i = -1;
        int j = nums.size() - 1;
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            if (nums[k] < target) {
                i = k;
            } else {
                j = k;
            }
        }
        return i;
    }

    int searchRange2(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        if (nums[0] > target) {
            return 0;
        }
        int i = 0;
        int j = nums.size();
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            if (nums[k] <= target) {
                i = k;
            } else {
                j = k;
            }
        }
        return j;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int i = searchRange1(nums, target);
        int j = searchRange2(nums, target);
        if (i + 1 == j) {
            return {-1, -1};
        } else {
            return {i + 1, j - 1};
        }
    }
};
