class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto [left, top, right, bottom] = std::make_tuple(-1, -1, (int) matrix[0].size(), (int) matrix.size());
        int direction = 2;
        int i = 0, j = 0;
        vector<int> result;
        while (left + 1 < right && top + 1 < bottom) {
            result.push_back(matrix[i][j]);
            switch (direction) {
                case 0: j--; break;
                case 1: i--; break;
                case 2: j++; break;
                case 3: i++; break;
            }
            if (j == left) {
                bottom--;
                direction = 1;
                i--; j++;
            } else if (i == top) {
                left++;
                direction = 2;
                i++; j++;
            } else if (j == right) {
                top++;
                direction = 3;
                i++; j--;
            } else if (i == bottom) {
                right--;
                direction = 0;
                i--; j--;
            }
        }
        return result;
    }
};
