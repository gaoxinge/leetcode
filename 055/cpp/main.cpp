class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m1 = -1;
        int m2 = 0;
        int m = 0;
        while (true) {
            for (int i = m1 + 1; i < m2 + 1; i++) {
                m = std::max(m, i + nums[i]);
                if (m >= nums.size() - 1) {
                    return true;
                }
            }
            if (m == m2) {
                return false;
            }
            m1 = m2;
            m2 = m;
        }
        return false;
    }
};
