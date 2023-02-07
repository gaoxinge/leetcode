class Solution {
public:
    vector<int> slide(string& s, map<string, int>& cnt0, int wordLen, int totalLen, int start) {
        map<string, int> cnt;
        vector<int> res;
        for (int i = start, j = start; j < s.size() - wordLen + 1; j += wordLen) {
            string word = s.substr(j, wordLen);
            if (cnt0.find(word) == cnt0.end()) {
                cnt.clear();
                i = j + wordLen;
                continue;
            }
            for (; cnt[word] == cnt0[word] && i < j; i += wordLen) {
                cnt[s.substr(i, wordLen)] -= 1;
            }
            cnt[word] += 1;
            if (j - i + wordLen == totalLen) {
                res.push_back(i);
            }
        }
        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        int totalLen = words.size() * wordLen;
        map<string, int> cnt;
        for (auto &word: words) {
            cnt[word] += 1;
        }
        
        vector<int> ress;
        for (int i = 0; i < wordLen; i++) {
            vector<int> res = slide(s, cnt, wordLen, totalLen, i);
            for (auto &r: res) {
                ress.push_back(r);
            }
        }
        return ress;
    }
};
