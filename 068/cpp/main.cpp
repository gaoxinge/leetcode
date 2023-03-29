class Solution {
public:
    string getLine(vector<string> line, int cnt, int maxWidth, bool last) {
        int spaceWidth1 = 1;
        int spaceWidth2 = 1;
        int k = 0;
        if (!last) {
            int m = maxWidth - cnt;
            int n = line.size() - 1 > 1 ? line.size() - 1 : 1;
            k = m % n;
            spaceWidth2 = m / n;
            spaceWidth1 = spaceWidth2 + 1;
        }
        string space1 = string(spaceWidth1, ' ');
        string space2 = string(spaceWidth2, ' ');
        string s = line[0];
        for (int i = 1; i < line.size(); i++) {
            string word = line[i];
            if (i <= k) {
                s += space1 + word;
            } else {
                s += space2 + word;
            }
        }
        return s + string(maxWidth - s.size(), ' ');
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cnt1 = words[0].size();
        int cnt2 = words[0].size();
        vector<string> line = {words[0]};
        vector<string> result;
        for (int i = 1; i < words.size(); i++) {
            string word = words[i];
            if (cnt1 + 1 + word.size() <= maxWidth) {
                cnt1 += 1 + word.size();
                cnt2 += word.size();
                line.push_back(word);
            } else {
                result.push_back(getLine(line, cnt2, maxWidth, false));
                cnt1 = word.size();
                cnt2 = word.size();
                line = {word};
            }
        }
        result.push_back(getLine(line, cnt2, maxWidth, true));
        return result;
    }
};
