class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        if (digits.size() == 1) {
            switch (digits[0]) {
                case '2': return {"a", "b", "c"};
                case '3': return {"d", "e", "f"};
                case '4': return {"g", "h", "i"};
                case '5': return {"j", "k", "l"};
                case '6': return {"m", "n", "o"};
                case '7': return {"p", "q", "r", "s"};
                case '8': return {"t", "u", "v"};
                case '9': return {"w", "x", "y", "z"};
            }
        }
        vector<string> r1 = letterCombinations(digits.substr(0, 1));
        vector<string> r2 = letterCombinations(digits.substr(1));
        vector<string> r;
        for (string &s1: r1) {
            for (string &s2: r2) {
                r.push_back(s1 + s2);
            }
        }
        return r;
    }
};
