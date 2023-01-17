class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.size();
        std::string r;
        int index;
        bool insert;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n / (numRows - 1) + 1; j++) {
                if (j % 2 == 0) {
                    index = j * (numRows - 1) + i;
                    insert = i != numRows - 1;
                } else {
                    index = j * (numRows - 1) + (numRows - 1 - i);
                    insert = i != 0;
                }
                if (index < n && insert) {
                    r += s[index];
                }
            }
        }
        return r;
    }
};
