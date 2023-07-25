class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s, int n) {
        if (n == 0) {
            if (s.empty()) {
                return {};
            }
            if (s[0] == '0') {
                if (s.size() == 1) {
                    return {"0"};
                } else {
                    return {};
                }
            }
            if (s.size() <= 3 && std::stoi(s) <= 255) {
                return {s};
            } else {
                return {};
            }
        }

        if (s.empty()) {
            return {};
        }

        std::set<std::string> result;

        std::string t1 = s.substr(0,1);
        std::string t2 = s.substr(1);
        auto result0 = restoreIpAddresses(t2, n - 1);
        for (auto &r:result0) {
            result.insert(t1 + "." + r);
        }
        if (s[0] == '0') {
            std::vector<std::string> result1(result.size());
            std::copy(result.begin(), result.end(), result1.begin());
            return result1;
        }

        if (s.size() >= 2) {
            t1 = s.substr(0, 2);
            t2 = s.substr(2);
            result0 = restoreIpAddresses(t2, n - 1);
            for (auto &r: result0) {
                result.insert(t1 + "." + r);
            }
        }

        if (s.size() >= 3) {
            t1 = s.substr(0, 3);
            t2 = s.substr(3);
            if (std::stoi(t1) <= 255) {
                result0 = restoreIpAddresses(t2, n - 1);
                for (auto &r: result0) {
                    result.insert(t1 + "." + r);
                }
            }
        }

        std::vector<std::string> result1(result.size());
        std::copy(result.begin(), result.end(), result1.begin());
        return result1;
    }

    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 3);
    }
};
