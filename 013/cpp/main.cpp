class Solution {
public:
    int getChar(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default:  return 1000;
        }
    }

    int romanToInt(string s) {
        int v0 = 0;
        int v1 = 0;
        int r = 0;
        for (int i = s.size() - 1; i > -1; i--) {
            char c = s[i];
            v1 = getChar(c);
            if (v1 < v0) {
                r -= v1;
            } else {
                r += v1;
            }
            v0 = v1;
        }
        return r;
    }
};
