class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        int n = nums.back();
        nums.pop_back();
        auto result = subsets(nums);
        int size = result.size();
        for (int i = 0; i < size; i++) {
            auto r = result[i];
            r.push_back(n);
            result.push_back(r);
        }
        return result;
    }
};
