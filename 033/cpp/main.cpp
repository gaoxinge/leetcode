class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            if (nums[i] < nums[k]) {
                if (target < nums[i]) {
                    i = k;
                } else if (target == nums[i]) {
                    return i;
                } else if (target < nums[k]) {
                    j = k;
                } else if (target == nums[k]) {
                    return k;
                } else {
                    i = k;
                }
            } else {
                if (target < nums[k]) {
                    j = k;
                } else if (target == nums[k]) {
                    return k;
                } else if (target < nums[i]) {
                    i = k;
                } else if (target == nums[i]) {
                    return i;
                } else {
                    j = k;
                }
            }
        }
        return nums[i] == target ? i : -1;
    }
};
