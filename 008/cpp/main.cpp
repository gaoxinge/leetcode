class Solution {
public:
    bool preCheck1(int r, int r0) {
        return r > 214748364 || (r == 214748364 && r0 > 7);
    }

    bool preCheck2(int r, int r0) {
        return r > 214748364 || (r == 214748364 && r0 >= 8);
    }

    bool preCheck(int r, int r0, int sign) {
        return sign > 0 ? preCheck1(r, r0) : preCheck2(r, r0);
    }

    int preReturn(int sign) {
        return sign > 0 ? 2147483647 : -2147483648;
    }

    bool isAlpha(char c) {
        return isalpha(c) || c == '.';
    }

    int myAtoi(string s) {
        int sign = 1;
        int r = 0;
        bool start = false;
        for (char &c: s) {
            bool isDigit = isdigit(c);

            if ((!start && isAlpha(c)) || (start && !isDigit)) {
                break;
            }

            if (!start) {
                if (c == '+') {
                    sign = 1;
                    start = true;
                    continue;
                } else if (c == '-') {
                    sign = -1;
                    start = true;
                    continue;
                } else if (isDigit) {
                    start = true;
                } else {
                    continue;
                }
            }

            int r0 = c - '0';
            if (preCheck(r, r0, sign)) {
                return preReturn(sign);
            }
            r *= 10;
            r += c - '0';
        }
        return sign * r;
    }
};
