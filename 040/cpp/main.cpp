class Solution {
public:
    vector<vector<int>> solve(vector<int>& candidates, int target, int i) {
        if (target == 0) {
            return {{}};
        }
        if (i >= candidates.size()) {
            return {};
        }
        vector<vector<int>> res;
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            int c = candidates[j];
            if (target < c) {
                continue;
            }   
            vector<vector<int>> res0 = solve(candidates, target - c, j + 1);
            for (vector<int> &re0: res0) {
                re0.insert(re0.begin(), c);
                res.push_back(re0);
            }
        }
        return res;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return solve(candidates, target, 0);
    }
};
