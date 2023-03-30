// https://en.wikipedia.org/wiki/Edit_distance
#define min(a, b) (a) < (b) ? (a) : (b)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> result1 = vector<int>(m + 1, 0);
        vector<int> result2 = vector<int>(m + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0) {
                    result2[j] = j;
                } else if (j == 0) {
                    result2[j] = i;
                } else {
                    char a = word1[j - 1];
                    char b = word2[i - 1];
                    if (a == b) {
                        result2[j] = result1[j - 1];
                    } else {
                        result2[j] = min(result1[j], result1[j - 1]);
                        result2[j] = min(result2[j], result2[j - 1]);
                        result2[j] += 1;
                    }
                }
            }
            result1 = result2;
            result2 = vector<int>(m + 1, 0);
        }
        return result1[m];
    }
};
