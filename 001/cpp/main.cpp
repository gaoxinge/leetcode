class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            int b = nums[i];
            if (auto p = cache.find(target - b); p != cache.end()) {
                return {p->second, i};
            }
            cache[b] = i;
        }
        return {};
    }
};
