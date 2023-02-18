class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            vector<int> nums0(nums);
            nums0.erase(nums0.begin() + i);
            auto res0 = permute(nums0);
            for (auto &r0: res0) {
                r0.insert(r0.begin(), t);
                res.push_back(r0);
            }
        }
        return res;
    }
};
