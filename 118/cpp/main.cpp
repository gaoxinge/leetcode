class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }

        auto result = generate(numRows - 1);
        auto r0 = result[result.size() - 1];

        vector<int> r = {};
        r.push_back(1);
        for (int i = 0; i < r0.size() - 1; i++) {
            r.push_back(r0[i] + r0[i + 1]);
        }
        r.push_back(1);

        result.push_back(r);
        return result;
    }
};
