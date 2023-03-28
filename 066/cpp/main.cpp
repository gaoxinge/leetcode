class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> result;
        int r = 1;
        for (int i = digits.size() - 1; i > -1; i--) {
            r += digits[i];
            result.insert(result.begin(), r % 10);
            r /= 10;
        }
        if (r > 0) {
            result.insert(result.begin(), r);
        }
        return result;
    }
};
