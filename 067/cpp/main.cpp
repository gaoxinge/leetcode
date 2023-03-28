class Solution {
public:
    string binaryAdd(char r, char c1, char c2) {
        if (r == '0' && c1 == '0' && c2 == '0') {
            return "00";
        }
        if (r == '0' && c1 == '0' && c2 == '1') {
            return "01";
        }
        if (r == '0' && c1 == '1' && c2 == '0') {
            return "01";
        }
        if (r == '0' && c1 == '1' && c2 == '1') {
            return "10";
        }
        if (r == '1' && c1 == '0' && c2 == '0') {
            return "01";
        }
        if (r == '1' && c1 == '0' && c2 == '1') {
            return "10";
        }
        if (r == '1' && c1 == '1' && c2 == '0') {
            return "10";
        }
        if (r == '1' && c1 == '1' && c2 == '1') {
            return "11";
        }
        return "";
    }

    string addBinary(string a, string b) {
        string s = "";
        char r = '0';
        int i = 1;
        while (i <= a.size() || i <= b.size()) {
            char c1 = i <= a.size() ? a[a.size() - i] : '0';
            char c2 = i <= b.size() ? b[b.size() - i] : '0';
            string p = binaryAdd(r, c1, c2);
            s = p[1] + s;
            r = p[0];
            i++;
        }
        if (r != '0') {
            s = r + s;
        }
        return s;
    }
};
