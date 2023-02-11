class Solution {
public:
    vector<tuple<int, int>> location(vector<vector<char>> &board) {
        vector<tuple<int, int>> t;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                }
            }
        }
        return t;
    }

    bitset<9> find(vector<vector<char>> &board, int i, int j) {
        bitset<9> b;
        for (int k = 0; k < 9; k++) {
            char c = board[i][k];
            if (c == '.') {
                continue;
            }
            b.set(c - '0' - 1);
        }
        for (int k = 0; k < 9; k++) {
            char c = board[k][j];
            if (c == '.') {
                continue;
            }
            b.set(c - '0' - 1);
        }
        for (int k = 0; k < 9; k++) {
            char c = board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3];
            if (c == '.') {
                continue;
            }
            b.set(c - '0' - 1);
        }
        b.flip();
        return b;
    }

    bool solve(vector<vector<char>> &board, vector<tuple<int, int>> &t, int k) {
        if (t.size() <= k) {
            return true;
        }
        auto [i, j] = t[k];
        auto b = find(board, i, j);
        for (int n = 0; n < 9; n++) {
            if (!b.test(n)) {
                continue;
            }
            board[i][j] = n + 1 + '0';
            if (solve(board, t, k + 1)) {
                return true;
            } 
        }
        board[i][j] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        auto t = location(board);
        solve(board, t, 0);
    }
};
