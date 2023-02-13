class Solution {
public:
    vector<vector<int>> solve(vector<int>& candidates, int target, int i) {
        if (i >= candidates.size()) {
            vector<vector<int>> t;
            if (target == 0) {
                t.push_back({});
            }
            return t;
        }
        int c = candidates[i];
        int r = target / c;
        vector<vector<int>> res;
        for (int k = 0; k < r + 1; k++) {
            vector<vector<int>> res0 = solve(candidates, target - k * c, i + 1);
            
            for (vector<int> &re0: res0) {
                for (int n = 0; n < k; n++) {
                    re0.insert(re0.begin(), c);
                }
                res.push_back(re0);
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return solve(candidates, target, 0);
    }
};
