class Solution {
public:
    string longestPalindrome1(string s, int i) {
        int n = std::min<int>(i, s.size() - i - 1);
        int j = 1;
        for (; j < n + 1; j++) {
            if (s[i - j] != s[i + j]) {
                break;
            }
        }
        return s.substr(i - j + 1, 2 * j - 1);
    }

    string longestPalindrome2(string s, int i) {
        int n = std::min<int>(i + 1, s.size() - i - 1);
        int j = 1;
        for (; j < n + 1; j++) {
            if (s[i - j + 1] != s[i + j]) {
                break;
            }
        }
        return s.substr(i - j + 2, 2 * j - 2);
    }

    string longestPalindrome(string s) {
        string r = "";
        for (int i = 0; i < s.size(); i++) {
            string r0;
            r0 = longestPalindrome1(s, i);
            if (r0.size() > r.size()) {
                r = r0;
            }
            r0 = longestPalindrome2(s, i);
            if (r0.size() > r.size()) {
                r = r0;
            }
        }
        return r;
    }
};
