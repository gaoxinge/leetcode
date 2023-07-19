int count(std::vector<int> &nums, int n, int num) {
    int c = 0;
    for (int i = n - 1; i > -1; i--) {
        if (nums[i] == num) {
            c++;
        } else {
            break;
        }
    }
    return c;
}

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums, int n) {
        if (n == 0) {
            return {{}};
        }

        int num = nums[n - 1];
        int c = count(nums, n, num);
        
        auto result = subsetsWithDup(nums, n - 1);
        for (int i = result.size() - 1; i > -1; i--) {
            auto r = result[i];
            if (count(r, r.size(), num) == c - 1) {
                auto s = r;
                s.push_back(num);
                result.push_back(s);
            }
        }
        return result;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return subsetsWithDup(nums, nums.size());
    }
};
