bool f(int x) {
    return (x & (x - 1)) == 0;
}

bool g(int x, int y) {
    return f(x ^ y);
}

std::vector<int> generate(int n, int x, int s, std::set<int> &seen) {
    std::vector<int> r;
    int y = 1;
    bool flag = s == -1;
    for (int i = 0; i < n; i++) {
        if (!flag) {
            if (x + y != s && x - y != s) {
                flag = true;
            }
            continue;
        }
        if (g(x, x + y)) {
            if (seen.find(x + y) == seen.end()) {
                r.push_back(x + y);
            }
        } else {
            if (seen.find(x - y) == seen.end()) {
                r.push_back(x - y);
            }
        }
        y <<= 1;
    }
    return r;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> paths{0};
        std::set<int> seen{0};

        int t = 0;
        int s = -1;
        int m = 1 << n;

        while (paths.size() <= m) {
            if (paths.size() == m) {
                if (g(0, t)) {
                    break;
                } else {
                    s = paths.back();
                    paths.pop_back();
                    seen.erase(s);
                    t = paths.back();
                    continue;
                }
            }

            std::vector<int> next = generate(n, t, s, seen);
            if (next.empty()) {
                s = paths.back();
                paths.pop_back();
                seen.erase(s);
                t = paths.back();
            } else {
                s = -1;
                paths.push_back(next[0]);
                seen.insert(next[0]);
                t = next[0];
            }
        }

        return paths;
    }
};
