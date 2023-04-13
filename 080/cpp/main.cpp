class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int i = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[i - 1]) {
                if (cnt == 1) {
                    nums[i++] = nums[j];
                    cnt++;
                } else {
                    // pass
                }
            } else {
                nums[i++] = nums[j];
                cnt = 1;
            }
        }
        return i;
    }
};
