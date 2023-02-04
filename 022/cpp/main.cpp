class Solution {
public:
    vector<string> f(int left, int right) {
        if (left == 0) {
            return {std::string(right, ')')};
        }
        
        std::vector<string> r;

        std::vector<string> r0 = f(left - 1, right + 1);
        for (auto &s: r0) {
            r.push_back("(" + s);
        }

        if (right > 0) {
            std::vector<string> r1 = f(left, right - 1);
            for (auto &s: r1) {
                r.push_back(")" + s);
            }
        }

        return r;
    }

    vector<string> generateParenthesis(int n) {
        return f(n, 0);
    }
};
