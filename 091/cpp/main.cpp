class Solution {
public:
    int numDecodings(string s) {
        int a = 0;
        if (s[0] != '0') {
            a++;
        }

        if (s.size() == 1 || a == 0) {
            return a;
        }

        int b = 0;
        if (s[1] != '0') {
            b++;
        }
        auto t = s.substr(0, 2);
        if (t >= "10" && t <= "26") {
            b++;
        }

        if (b == 0) {
            return 0;
        }

        for (int i = 2; i < s.size(); i++) {
            int r = 0;
            if (s[i] != '0') {
                r += b;
            }
            t = s.substr(i - 1, 2);
            if (t >= "10" && t <= "26") {
                r += a;
            }

            a = b;
            b = r;

            if (r == 0) {
                return 0;
            }
        }
        return b;   
    }
};
