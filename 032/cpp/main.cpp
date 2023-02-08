class Solution {
public:
    int longestValidParentheses(string s) {
        int m = 0;
        vector<int> stack;
        int k = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                if (stack.empty()) {
                    k = i;
                    continue;
                }
                stack.pop_back();
                int j = !stack.empty() ? stack.back() : k;
                m = std::max(m, i - j);
            }
        }
        return m;
    }
};
