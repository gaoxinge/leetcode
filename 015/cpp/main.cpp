class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> r;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int target0 = nums[j] + nums[k];
                if (target0 < target) {
                    j += 1;
                    while (j < k) {
                        if (nums[j] == nums[j - 1]) {
                            j += 1;
                        } else {
                            break;
                        }
                    }
                } else if (target0 > target) {
                    k -= 1;
                    while (j < k) {
                        if (nums[k] == nums[k + 1]) {
                            k -= 1;
                        } else {
                            break;
                        }
                    }
                } else {
                    r.push_back({-target, nums[j], nums[k]});
                    j += 1;
                    k -= 1;
                    while (j < k) {
                        if (nums[j] == nums[j - 1]) {
                            j += 1;
                        } else {
                            break;
                        }
                    }
                    while (j < k) {
                        if (nums[k] == nums[k + 1]) {
                            k -= 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return r;
    }
};
