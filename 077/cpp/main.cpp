class Solution {
public:
    vector<vector<int>> combine(vector<int> ns, int k) {
        if (ns.size() < k) {
            return {};
        }
        if (ns.size() == k) {
            return {ns};
        }
        int n = ns.back();
        ns.pop_back();
        auto result = combine(ns, k);
        auto result0 = combine(ns, k - 1);
        for (auto &r0: result0) {
            r0.push_back(n);
            result.push_back(r0);
        }
        return result;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ns;
        for (int i = 0; i < n; i++) {
            ns.push_back(i + 1);
        }
        return combine(ns, k);
    }
};
