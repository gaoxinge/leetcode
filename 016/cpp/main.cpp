class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int r = nums[0] + nums[1] + nums[2] - target;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int t0 = t + nums[j] + nums[k] - target;
                if (std::abs(t0) < std::abs(r)) {
                    r = t0;
                }
                if (t0 < 0) {
                    j++;
                } else if (t0 > 0) {
                    k--;
                } else {
                    return target;
                }
            } 
        }
        return r + target;
    }
};
