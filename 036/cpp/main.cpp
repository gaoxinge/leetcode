class Solution {
public:
    bool valid1(vector<vector<char>>& board, int i) {
        std::set<char> s;
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            if (s.find(c) != s.end()) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    bool valid2(vector<vector<char>>& board, int i) {
        std::set<char> s;
        for (int j = 0; j < 9; j++) {
            char c = board[j][i];
            if (c == '.') {
                continue;
            }
            if (s.find(c) != s.end()) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    bool valid3(vector<vector<char>>& board, int i) {
        std::set<char> s;
        for (int j = 0; j < 9; j++) {
            char c = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];
            if (c == '.') {
                continue;
            }
            if (s.find(c) != s.end()) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!valid1(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!valid2(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!valid3(board, i)) {
                return false;
            }
        }
        return true;
    }
};
