class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bitset<100000> b;
        for (auto &num: nums) {
            if (num > 0 && num <= nums.size()) {
                b.set(num - 1);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!b.test(i)) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
