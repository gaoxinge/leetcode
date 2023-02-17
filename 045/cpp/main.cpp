class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int k = 0;
        int m1 = -1;
        int m2 = 0;
        while (true) {
            int m = 0;
            for (int i = m1 + 1; i < m2 + 1; i++) {
                m = std::max(m, i + nums[i]);
                if (m >= nums.size() - 1) {
                    return k + 1;
                }
            }
            k += 1;
            m1 = m2;
            m2 = m;
        }
        return -1;
    }
};
