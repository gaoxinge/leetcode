class Solution {
public:
    string gen(string s) {
        map<char, int> m;
        for (auto &c: s) {
            m[c] += 1;
        }
        string str;
        for (auto &c: "abcdefghijklmnopqrstuvwxyz") {
            str += to_string(m[c]);
            str += ":";
        }
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;
        for (auto &str: strs) {
            auto key = gen(str);
            groups[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto &[key, val]: groups) {
            res.push_back(val);
        }
        return res;
    }
};
