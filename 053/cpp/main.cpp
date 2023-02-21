class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int t = 0;
        int m = nums[0];
        for (auto &num: nums) {
            t += num;
            if (t > 0) {
                m = std::max(m, t);
            } else {
                m = std::max(m, num);
                t = 0;
            }
        }
        return m;
    }
};
