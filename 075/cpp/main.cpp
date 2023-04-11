class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }

    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        while (i <= k && k <= j) {
            while (i <= k && k <= j) {
                int n = nums[k];
                if (n == 0) {
                    swap(nums, i, k);
                    i += 1;
                } else if (n == 2) {
                    swap(nums, k, j);
                    j -= 1;
                } else {
                    break;
                }
            }
            k += 1;
        }
    }
};
