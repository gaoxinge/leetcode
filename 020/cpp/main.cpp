class Solution {
public:
    bool isValid(string s) {
        std::vector<char> v;
        for (auto &c: s) {
            if (c == '(' || c == '[' || c == '{') {
                v.push_back(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (!v.empty()) {
                    char c0 = v.back();
                    if ((c0 == '(' && c == ')') || (c0 == '[' && c == ']') || (c0 == '{' && c == '}')) {
                        v.pop_back();
                        continue;
                    }
                }
                return false;
            }
        }
        return v.empty();
    }
};
