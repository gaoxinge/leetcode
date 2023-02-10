use std::collections::HashSet;

impl Solution {
    fn valid1(board: &Vec<Vec<char>>, i: usize) -> bool {
        let mut s = HashSet::new();
        for j in 0..9 {
            let c = board[i][j];
            if c == '.' {
                continue;
            }
            if s.contains(&c) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    fn valid2(board: &Vec<Vec<char>>, i: usize) -> bool {
        let mut s = HashSet::new();
        for j in 0..9 {
            let c = board[j][i];
            if c == '.' {
                continue;
            }
            if s.contains(&c) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    fn valid3(board: &Vec<Vec<char>>, i: usize) -> bool {
        let mut s = HashSet::new();
        for j in 0..9 {
            let c = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];
            if c == '.' {
                continue;
            }
            if s.contains(&c) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        for i in 0..9 {
            if !Solution::valid1(&board, i) {
                return false;
            }
        }
        for i in 0..9 {
            if !Solution::valid2(&board, i) {
                return false;
            }
        }
        for i in 0..9 {
            if !Solution::valid3(&board, i) {
                return false;
            }
        }
        return true;
    }
}
