class Solution {
public:
    int uniquePaths(int m, int n, map<tuple<int, int>, int> &cache) {
        if (m == 1) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }

        tuple<int, int> xy = {m, n};
        auto p = cache.find(xy);
        if (p != cache.end()) {
            return p->second;
        }

        int k = uniquePaths(m - 1, n, cache) + uniquePaths(m, n - 1, cache);
        cache[{m, n}] = k;
        return k;
    }

    int uniquePaths(int m, int n) {
        map<tuple<int, int>, int> cache;
        return uniquePaths(m, n, cache);
    }
};
