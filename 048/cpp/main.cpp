class Solution {
public:
    tuple<int, int> rotateAxis(tuple<int, int> axis, int n) {
        auto [i, j] = axis;
        return {j, n - 1 - i};
    }

    vector<tuple<int, int>> generate(tuple<int, int> axis, int n) {
        auto [i, j] = axis;
        if (n % 2 == 1 && i == n / 2 && j == n / 2) {
            return {{i, j}};
        }
        vector<tuple<int, int>> res;
        res.push_back(axis);
        res.push_back(rotateAxis(res[res.size() - 1], n));
        res.push_back(rotateAxis(res[res.size() - 1], n));
        res.push_back(rotateAxis(res[res.size() - 1], n));
        return res;
    }

    void swap0(vector<vector<int>>& matrix, tuple<int, int> axis1, tuple<int, int> axis2) {
        auto [i1, j1] = axis1;
        auto [i2, j2] = axis2;
        int t = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = t;
    }

    void swap(vector<vector<int>>& matrix, vector<tuple<int, int>>& axiss) {
        if (axiss.size() == 1) {
            return;
        }
        swap0(matrix, axiss[0], axiss[3]);
        swap0(matrix, axiss[3], axiss[2]);
        swap0(matrix, axiss[2], axiss[1]);
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                auto axiss = generate({i, j}, n);
                swap(matrix, axiss);
            }
        }
    }
};
