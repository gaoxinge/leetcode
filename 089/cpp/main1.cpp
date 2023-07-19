class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            return {0, 1};
        }
        int m = 1 << (n - 1);
        std::vector<int> r = grayCode(n - 1);
        for (int i = r.size() - 1; i > - 1; i--) {
            r.push_back(m | r[i]);
        }
        return r;
    }
};
