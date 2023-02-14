class Solution {
public:
    vector<string> split(string p) {
        int last = 0;
        string s;
        vector<string> r;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] != '*') {
                s.append(string(1, p[i]));
                continue;
            }
            if (!s.empty()) {
                r.push_back(s);
            }
            s = "";
        }
        if (!s.empty()) {
            r.push_back(s);
        }
        return r;
    }

    bool startsWith(string s, string p, int pos) {
        if (s.size() - pos < p.size()) {
            return false;
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[i] != '?' && s[i + pos] != p[i]) {
                return false;
            }
        }
        return true;
    }

    bool endsWith(string s, string p, int pos) {
        if (s.size() - pos < p.size()) {
            return false;
        }
        for (int i = 0; i < p.size(); i++) {
            if (p[p.size() - 1 - i] != '?' && s[s.size() - 1 - i] != p[p.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isMatch(string s, string p, int pos) {
        if (s.size() - pos != p.size()) {
            return false;
        }
        return startsWith(s, p, pos);
    }

    int find(string s, string p, int pos) {
        if (s.size() - pos < p.size()) {
            return -1;
        }
        for (int i = pos; i < s.size() - p.size() + 1; i++) {
            if (startsWith(s, p, i)) {
                return i; 
            }
        }
        return -1;
    }

    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        int pos = 0;
        vector<string> ps = split(p);
        for (int i = 0; i < ps.size(); i++) {
            bool isStart = i == 0 && p[0] != '*';
            bool isEnd = i == ps.size() - 1 && p[p.size() - 1] != '*';
            if (isStart && isEnd) {
                return isMatch(s, p, pos);
            }
            if (isEnd) {
                if (!endsWith(s, ps[i], pos)) {
                    return false;
                }
                continue;
            }
            pos = find(s, ps[i], pos);
            if (isStart) {
                if (pos != 0) {
                    return false;
                }
            }
            if (pos == -1) {
                return false;
            }
            pos += ps[i].size();
        }
        return true;
    }
};
