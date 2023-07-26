class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 1;
        }
        int cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            cnt += 2 * numTrees(i) * numTrees(n - 1 - i);
        }
        if (n % 2 == 1) {
            int c = numTrees(n / 2);
            cnt += c * c;
        }
        return cnt;
    }
};
