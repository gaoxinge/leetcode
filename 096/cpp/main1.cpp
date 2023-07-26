class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        std::vector<int> result = {1, 1};
        for (int i = 2; i < n + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < i / 2; j++) {
                cnt += 2 * result[j] * result[i - 1 - j];
            }
            if (i % 2 == 1) {
                cnt += result[i / 2] * result[i / 2];
            }
            result.push_back(cnt);
        }
        return result.back();
    }
};
