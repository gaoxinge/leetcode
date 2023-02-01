class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long target0 = target;
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> r;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                long t = target0 - nums[i] - nums[j];
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long t0 = nums[k] + nums[l];
                    if (t0 < t) {
                        k += 1;
                    } else if (t0 > t) {
                        l -= 1;
                    } else {
                        r.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k += 1;
                        l -= 1;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k += 1;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l -= 1;
                        }
                    }
                }
            }
        }
        return r;
    }
};
