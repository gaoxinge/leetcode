impl Solution {
    pub fn get_nexts(board: &Vec<Vec<char>>, c: char, i: usize, j: usize) -> Vec<(usize, usize)> {
        let m = board.len();
        let n = board[0].len();
        let mut result = Vec::new();
        if i != 0 && board[i - 1][j] == c {
            result.push((i - 1, j));
        }
        if i != m - 1 && board[i + 1][j] == c {
            result.push((i + 1, j));
        }
        if j != 0 && board[i][j - 1] == c {
            result.push((i, j - 1));
        }
        if j != n - 1 && board[i][j + 1] == c {
            result.push((i, j + 1));
        }
        return result;
    }

    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let m = board.len();
        let n = board[0].len();
        let word = word.as_bytes();
        for i in 0..m {
            for j in 0..n {
                let b = board[i][j];
                let c = word[0] as char;
                if b != c {
                    continue
                }

                let mut paths = vec![(i, j)];
                if paths.len() == word.len() {
                    return true;
                }
                let mut nextss = vec![Solution::get_nexts(&board, word[paths.len()] as char, i, j)];

                while !paths.is_empty() {
                    let mut nexts = nextss.pop().unwrap();
                    while !nexts.is_empty() {
                        let next = nexts.pop().unwrap();
                        if paths.contains(&(next.0, next.1)) {
                            continue
                        }
                        paths.push(next);
                        if paths.len() == word.len() {
                            return true;
                        }
                        let nexts0 = Solution::get_nexts(&board, word[paths.len()] as char, next.0, next.1);
                        nextss.push(nexts);
                        nextss.push(nexts0);
                        break;
                    }
                    if paths.len() > nextss.len() {
                        paths.pop();
                    }
                }
            }
        }
        return false;
    }
}
