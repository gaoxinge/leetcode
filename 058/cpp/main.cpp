class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = s.size() - 1; i > -1; i--) {
            if (s[i] != ' ') {
                cnt += 1;
            } else if (cnt > 0) {
                break;
            }
        }
        return cnt;
    }
};

