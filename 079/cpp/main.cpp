class Solution {
public:
    vector<tuple<int, int>> getNexts(vector<vector<char>>& board, char c, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        vector<tuple<int, int>> result;
        if (i != 0 && board[i - 1][j] == c) {
            result.push_back({i - 1, j});
        }
        if (i != m - 1 && board[i + 1][j] == c) {
            result.push_back({i + 1, j});
        }
        if (j != 0 && board[i][j - 1] == c) {
            result.push_back({i, j - 1});
        }
        if (j != n - 1 && board[i][j + 1] == c) {
            result.push_back({i, j + 1});
        }
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        reverse(word.begin(), word.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char b = board[i][j];
                char c = word[0];
                if (b != c) {
                    continue;
                }

                vector<tuple<int, int>> paths = {{i, j}};
                board[i][j] = '#';
                if (paths.size() == word.size()) {
                    return true;
                }
                vector<vector<tuple<int, int>>> nextss = {getNexts(board, word[paths.size()], i, j)};

                while (!paths.empty()) {
                    auto nexts = nextss.back();
                    nextss.pop_back();
                    while (!nexts.empty()) {
                        auto next = nexts.back();
                        nexts.pop_back();
                        int t1 = get<0>(next);
                        int t2 = get<1>(next);
                        if (board[t1][t2] == '#') {
                            continue;
                        }
                        paths.push_back(next);
                        board[t1][t2] = '#';
                        if (paths.size() == word.size()) {
                            return true;
                        }
                        nextss.push_back(nexts);
                        nextss.push_back(getNexts(board, word[paths.size()], t1, t2));
                        break;
                    }
                    if (paths.size() > nextss.size()) {
                        auto path = paths.back();
                        paths.pop_back();
                        board[get<0>(path)][get<1>(path)] = word[paths.size()];
                    }
                }
            }
        }
        return false;
    }
};
