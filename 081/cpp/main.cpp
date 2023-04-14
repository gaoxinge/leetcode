class Solution {
public:
    bool search(vector<int>& nums, int target, int i, int j) {
        if (i + 1 >= j) {
            return nums[i] == target || nums[j] == target;
        }

        int k = i + (j - i) / 2;
        if (nums[i] == target || nums[j] == target || nums[k] == target) {
            return true;
        }

        if (nums[i] == nums[j]) {
            return search(nums, target, i, k) || search(nums, target, k, j);
        }

        if (nums[i] < nums[j]) {
            if (nums[k] < target) {
                return search(nums, target, k, j);
            } else {
                return search(nums, target, i, k);
            }
        }

        if (nums[k] < nums[i]) {
            if (nums[k] < target) {
                if (nums[i] < target) {
                    return search(nums, target, i, k);
                } else {
                    return search(nums, target, k, j);
                }
            } else {
                return search(nums, target, i, k);
            }
        }

        if (nums[k] < target) {
            return search(nums, target, k, j);
        } else {
            if (nums[i] < target) {
                return search(nums, target, i, k);
            } else {
                return search(nums, target, k, j);
            }
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};
