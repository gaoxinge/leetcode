class Solution {
public:
    void gen(vector<vector<int>> &ms, int k, int n, int v) {
        if (n == 0) {
            return;
        }
        if (n == 1) {
            ms[k][k] = v;
            return;
        }
        for (int j = k; j < k + n - 1; j++) {
            ms[k][j] = v++;
        }
        for (int i = k; i < k + n - 1; i++) {
            ms[i][k + n - 1] = v++;
        }
        for (int j = k + n - 1; j > k; j--) {
            ms[k + n - 1][j] = v++;
        }
        for (int i = k + n - 1; i > k; i--) {
            ms[i][k] = v++;
        }
        gen(ms, k + 1, n - 2, v);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ms;
        for (int i = 0; i < n; i++) {
            vector<int> m;
            for (int j = 0; j < n; j++) {
                m.push_back(0);
            }
            ms.push_back(m);
        }
        gen(ms, 0, n, 1);
        return ms;
    }
};
