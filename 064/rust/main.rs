use std::cmp::min;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut rs = vec![-1; n];
        for i in (0..m).rev() {
            for j in (0..n).rev() {
                let g = grid[i][j];
                if rs[j] == -1 && j == n - 1 {
                    rs[j] = g;
                } else if rs[j] == -1 {
                    rs[j] = rs[j + 1] + g;
                } else if j == n - 1 {
                    rs[j] += g;
                } else {
                    rs[j] = min(rs[j], rs[j + 1]) + g; 
                }
            }
        }
        return rs[0];
    }
}
