class Solution {
public:
    string intToRoman(int num) {
        std::string x[4][9] = {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM"}
        };

        std::string r;
        for (int i = 0; i < 4; i++) {
            int t = num % 10;
            if (t > 0) {
                r = x[i][t - 1] + r;
            }
            num /= 10;
        }
        return r;
    }
};
