class Solution {
public:
    string multiply1(string num1, char p) {
        int q = 0;
        string s;
        for (int i = num1.size() - 1; i > -1; i--) {
            q += (num1[i] - '0') * (p - '0');
            s = string(1, q % 10 + '0') + s;
            q /= 10;
        }
        if (q > 0) {
            s = string(1, q + '0') + s;
        }
        return s;
    }

    string add(string num1, string num2) {
        int q = 0;
        int n1 = num1.size();
        int n2 = num2.size();
        int n = max(n1, n2);
        string s;
        for (int i = 0; i < n; i++) {
            char a = n1 >= i + 1 ? num1[n1 - 1 - i] : '0';
            char b = n2 >= i + 1 ? num2[n2 - 1 - i] : '0';
            q += ((a - '0') + (b - '0'));
            s = string(1, q % 10 + '0') + s;
            q /= 10;
        }
        if (q > 0) {
            s = string(1, q + '0') + s;
        }
        return s;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string s2 = multiply1(num1, num2[num2.size() - 1]);
        if (num2.size() == 1) {
            return s2;
        }
        string s1 = multiply(num1, num2.substr(0, num2.size() - 1));
        return add(s1 + "0", s2);
    }
};
