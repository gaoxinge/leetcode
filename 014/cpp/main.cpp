class Solution {
public:
    bool isSame(vector<string>& strs, int i) {
        if (strs.empty()) {
            return false;
        }

        for (auto &str: strs) {
            if (str.size() <= i) {
                return false;
            }
        }

        char c = strs[0][i];
        for (auto &str: strs) {
            if (str[i] != c) {
                return false;
            }
        }

        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        std::string r;
        for (int i = 0; i < 200; i++) {
            if (!isSame(strs, i)) {
                return r;
            }
            r += strs[0][i];
        }
        return r;
    }
};
