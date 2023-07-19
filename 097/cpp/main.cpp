class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int mn = s3.size();
        if (m + n != mn) {
            return false;
        }

        vector<vector<bool>> r;
        for (int i = 0; i < m + 1; i++) {
            vector<bool> t;
            for (int j = 0; j < n + 1; j++) {
                t.push_back(true);
            }
            r.push_back(t);
        }

        for (int i = 1; i < m + 1; i++) {
            r[i][0] = r[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j < n + 1; j++) {
            r[0][j] = r[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                r[i][j] = (s1[i - 1] == s3[i + j - 1] && r[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && r[i][j - 1]);
            }
        }

        return r[m][n];
    }
};
