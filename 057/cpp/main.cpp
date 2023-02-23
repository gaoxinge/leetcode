class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isPush = false;
        vector<vector<int>> r;
        for (auto &interval: intervals) {
            if (isPush || interval[1] < newInterval[0]) {
                r.push_back(interval);
            } else if (newInterval[1] < interval[0]) {
                r.push_back(newInterval);
                r.push_back(interval);
                isPush = true;
            } else {
                newInterval = {std::min(interval[0], newInterval[0]), std::max(interval[1], newInterval[1])};
            }
        }
        if (!isPush) {
            r.push_back(newInterval);
        } 
        return r;
    }
};
