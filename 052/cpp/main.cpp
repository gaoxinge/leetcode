class Solution {
public:
    vector<tuple<int, int>> init(int n) {
        vector<tuple<int, int>> ms;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ms.push_back({i, j});
            }
        }
        return ms;
    }

    void gen(vector<tuple<int, int>> &ms, tuple<int, int> ij0) {
        auto [i0, j0] = ij0;
        for (int k = ms.size() - 1; k > -1; k--) {
            auto [i, j] = ms[k];
            if (i == i0 || j == j0 || abs(i - i0) == abs(j - j0)) {
                ms.erase(ms.begin() + k);
            }
        }
    }

    vector<vector<tuple<int, int>>> solveNQueens(vector<tuple<int, int>> &ms, int n, int m) {
        if (n == 0) {
            return {{}};
        }
        vector<vector<tuple<int, int>>> res;
        for (int k = 0; k < ms.size(); k++) {
            auto [i, j] = ms[k];
            if (i != m) {
                continue;
            }
            auto ms0(ms);
            gen(ms0, {i, j});
            auto res0 = solveNQueens(ms0, n - 1, m + 1);
            for (auto &r0: res0) {
                r0.insert(r0.begin(), {i, j});
                res.push_back(r0);
            }
        }
        return res;
    }

    int totalNQueens(int n) {
        auto ms = init(n);
        auto res = solveNQueens(ms, n, 0);
        return res.size();
    }
};
