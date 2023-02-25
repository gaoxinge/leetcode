impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let grid = obstacle_grid;
        let m = grid.len();
        let n = grid[0].len();
        let mut cache = vec![0; n];
        for i in 0..m {
            let gs = &grid[m - 1 - i];
            for j in 0..n {
                let g = gs[n - 1 - j];
                if g == 1 {
                    cache[j] = 0;
                } else if i == 0 && j == 0 {
                    cache[j] = 1;
                } else if j == 0 {
                    cache[j] = cache[j];
                } else {
                    cache[j] += cache[j - 1];
                }
            }
        }
        return cache[n - 1];
    }
}
