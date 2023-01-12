class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        std::map<char, int> cache;
        for (int i = 0, j = 0; j < s.size(); j++) {
            while (cache.find(s[j]) != cache.end()) {
                cache.erase(s[i++]);
            }
            cache[s[j]] = 1;
            m = std::max(m, j - i + 1);
        }
        return m;
    }
};
