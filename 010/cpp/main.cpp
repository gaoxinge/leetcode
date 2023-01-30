class Solution {
public:
    std::vector<string> parsePattern(string p) {
        std::vector<string> ss;
        std::string s;
        for (char &c: p) {
            if (s.empty()) {
                s = c;
                continue;
            }
            
            if (c != '*') {
                ss.push_back(s);
                s = c;
            } else {
                ss.push_back(s + '*');
                s = "";
            }
        }
        if (!s.empty()) {
            ss.push_back(s);
        }
        return ss;
    } 

    std::vector<string> simplify(std::vector<string> ps) {
        if (ps.empty()) {
            return ps;
        }
        std::vector<string> ps0;
        string p = ps[0];
        for (int i = 1; i < ps.size(); i++) {
            string p0 = ps[i];
            if (p0 == p && p != ".*" && p.size() > 1) {
                continue;
            }
            ps0.push_back(p);
            p = p0;
        }
        ps0.push_back(p);
        return ps0;
    }

    bool match(string s, string p) {
        if (p == ".*") {
            return true;
        }
        if (p.size() > 1) {
            char p0 = p[0];
            for (char &c: s) {
                if (c != p0) {
                    return false;
                }
            }
            return true;
        }
        if (p == ".") {
            return s.size() == 1;
        }
        return s == p;
    }

    bool isMatch(string s, std::vector<string> ps, int k) {
        if (k >= ps.size()) {
            return s.empty();
        }
        for (int i = 0; i < s.size() + 1; i++) {
            string s1 = s.substr(0, i);
            if (!match(s1, ps[k])) {
                if (i == 0) {
                    continue;
                }
                return false;
            }
            string s2 = s.substr(i, s.size() - i);
            if (isMatch(s2, ps, k + 1)) {
                return true;
            }
        }
        return false;
    }

    bool isMatch(string s, string p) {
        std::vector<string> ps = simplify(parsePattern(p));
        return isMatch(s, ps, 0);
    }
};
