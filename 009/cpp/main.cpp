class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int x0 = -1;
        int y = 0;
        while (x > y) {
            y *= 10;
            y += x % 10;
            x0 = x;
            x /= 10;
        }
        return y == x || y == x0;
    }
};
