use std::collections::HashSet;

impl Solution {
    fn location(board: &Vec<Vec<char>>) -> Vec<(usize, usize)> {
        let mut t = Vec::new();
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] == '.' {
                    t.push((i, j));
                }
            }
        }
        return t;
    }

    fn find(board: &Vec<Vec<char>>, i: usize, j: usize) -> HashSet<char> {
        let mut s1 = HashSet::new();
        for k in 0..9 {
            let c = board[i][k];
            if c == '.' {
                continue;
            }
            s1.insert(c);
        }
        for k in 0..9 {
            let c = board[k][j];
            if c == '.' {
                continue;
            } 
            s1.insert(c);
        }
        for k in 0..9 {
            let c = board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3];
            if c == '.' {
                continue;
            }
            s1.insert(c);
        }

        let mut s2 = HashSet::new();
        for c in vec!['1', '2', '3', '4', '5', '6', '7', '8', '9'] {
            if !s1.contains(&c) {
                s2.insert(c);
            }
        }
        return s2;
    }

    pub fn solve(board: &mut Vec<Vec<char>>, location: &mut Vec<(usize, usize)>, k: usize) -> bool {
        if location.len() <= k {
            return true;
        }
        let (i, j) = location[k];
        let s = Solution::find(board, i, j);
        for c in s {
            board[i][j] = c;
            if Solution::solve(board, location, k + 1) {
                return true;
            }
        }
        board[i][j] = '.';
        return false;
    }

    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let mut location = Solution::location(board);
        Solution::solve(board, &mut location, 0);
    }
}
