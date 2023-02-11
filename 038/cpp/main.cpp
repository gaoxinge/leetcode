class Solution {
public:
    vector<string> g1(string a) {
        int i = 0;
        vector<string> r;
        for (int j = 1; j < a.size(); j++) {
            if (a[j] != a[i]) {
                r.push_back(a.substr(i, j - i));
                i = j;
            }
        }
        r.push_back(a.substr(i));
        return r;
    }

    string g2(string a) {
        vector<string> r = g1(a);
        string s;
        for (string &c: r) {
            s += std::to_string(c.size()) + c[0];
        }
        return s;
    }

    string countAndSay(int n) {
        string m = "1";
        for (int i = 1; i < n; i++) {
            m = g2(m);
        }
        return m;
    }
};
