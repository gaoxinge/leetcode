class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });
        vector<vector<int>> results;
        for (auto &b: intervals) {
            if (results.empty()) {
                results.push_back(b);
                continue;
            }
            auto a = results.back();
            if (a[1] < b[0]) {
                results.push_back(b);
            } else {
                results.pop_back();
                results.push_back({a[0], std::max(a[1], b[1])});
            }
        }
        return results;
    }
};
