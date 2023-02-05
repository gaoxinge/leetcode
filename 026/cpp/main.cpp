class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (auto &n: nums) {
            if (nums[k - 1] == n) {
                continue;
            }
            nums[k++] = n;
        }
        return k;
    }
};
