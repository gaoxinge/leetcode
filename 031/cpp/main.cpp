class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    bool swap(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            return false;
        }
        if (swap(nums, i + 1)) {
            return true;
        }
        bool r = false;
        for (int j = nums.size() - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                swap(nums, i, j);
                r = true;
                break;
            }
        }
        if (!r) {
            return false;
        }
        std::reverse(nums.begin() + i + 1, nums.end());
        return true;
    }

    void nextPermutation(vector<int>& nums) {
        if (!swap(nums, 0)) {
            std::reverse(nums.begin(), nums.end());
        }
    }
};
