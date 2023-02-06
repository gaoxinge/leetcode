class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        double d = 1.0 * dividend / divisor;
        return d < 0 ? std::ceil(d) : std::floor(d);
    }
};
