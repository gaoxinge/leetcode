class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = -1;
        int j = m * n;
        while (i + 1 < j) {
            int k = i + (j - i) / 2;
            int t = matrix[k / n][k % n];
            if (t == target) {
                return true;
            } else if (t < target) {
                i = k;
            } else {
                j = k;
            }
        }

        if (i > -1 && matrix[i / n][i % n] == target) {
            return true;
        }
        if (j < m * n && matrix[j / n][j % n] == target) {
            return true;
        }
        return false;
    }
};
