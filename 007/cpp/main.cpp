class Solution {
public:
    int sign(int x) {
        return x >= 0 ? 1 : -1;
    }

    int abs(int x) {
        return x >= 0 ? x : -x;
    }

    int preCheck(int r, int r0) {
        return r > 214748364 || (r == 214748364 && r0 > 7);
    }

    int reverse(int x) {
        // [-2147483648, 2147483647]
        if (x == -2147483648) {
            return 0;
        }

        // [-2147483647, 2147483647]
        int s = sign(x);
        int y = abs(x);
        
        // [0, 2147483647]        
        int r = 0;
        while (y > 0) {
            int r0 = y % 10;
            if (preCheck(r, r0)) {
                return 0;
            }
            r *= 10;
            r += r0;
            y /= 10;
        }
        return s * r;
    }
};
