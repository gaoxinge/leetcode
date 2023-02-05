class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (auto &n: nums) {
            if (n == val) {
                continue;
            }
            nums[k++] = n;
        }
        return k;
    }
};
