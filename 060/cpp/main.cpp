class Solution {
public:
    int frac(int n) {
        if (n == 1) {
            return 1;
        }
        return n * frac(n - 1);
    }

    string getPermutation(int n, int k) {
        vector<int> ms;
        for (int i = 0; i < n; i++) {
            ms.push_back(i + 1);
        }
        int m = frac(n);
        k -= 1;
        string s = "";
        for (int i = n; i > 0; i--) {
            m /= i;
            int j = k / m;
            s.append(std::to_string(ms[j]));
            ms.erase(ms.begin() + j);
            k %= m;
        }
        return s;
    }
};
