class Check {
private:
    std::map<char, int> m1;
    std::map<char, int> m2;
    std::set<char> m3;

public:
    explicit Check(const string &t) {
        for (const char &c: t) {
            if (m1.find(c) == m1.end()) {
                m1[c] = 0;
            }
            m1[c] += 1;
            m2[c] = 0;
            m3.insert(c);
        }
    }

    void add(const char &c) {
        if (m1.find(c) == m1.end()) {
            return;
        }
        m2[c] += 1;
        if (m2[c] >= m1[c]) {
            m3.erase(c);
        }
    }

    void remove(const char &c) {
        if (m1.find(c) == m1.end()) {
            return;
        }
        m2[c] -= 1;
        if (m2[c] < m1[c]) {
            m3.insert(c);
        }

    }

    bool check() {
        return m3.empty();
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        string r = "";
        Check check(t);
        check.add(s[0]);
        while (j < s.size() || check.check()) {
            if (check.check()) {
                check.remove(s[i++]);
                if (!check.check()) {
                    if (r.empty() || j - i + 2 < r.size()) {
                        r = s.substr(i - 1, j - i + 2);
                    }
                }
            } else {
                check.add(s[++j]);
            }
        }
        return r;
    }
};
