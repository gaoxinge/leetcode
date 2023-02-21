impl Solution {
    fn init(n: usize) -> Vec<(usize, usize)> {
        let mut ms = Vec::new();
        for i in 0..n {
            for j in 0..n {
                ms.push((i, j));
            }
        }
        return ms;
    }

    fn gen(ms: &Vec<(usize, usize)>, ij0: (usize, usize)) -> Vec<(usize, usize)> {
        let mut ms0 = Vec::new();
        let (i0, j0) = ij0;
        for m in ms {
            let (i, j) = *m;
            if i == i0 || j == j0 || (i as i32 - i0 as i32).abs() == (j as i32 - j0 as i32).abs() {
                continue;
            }
            ms0.push(m.clone());
        }
        return ms0;
    }

    fn solve(ms: &Vec<(usize, usize)>, n: usize, m: usize) -> Vec<Vec<(usize, usize)>> {
        if n == 0 {
            return vec![Vec::new()];
        }
        let mut res = Vec::new();
        for k in 0..ms.len() {
            let (i, j) = ms[k];
            if i != m {
                continue;
            }
            let ms0 = Solution::gen(ms, (i, j));
            let res0 = Solution::solve(&ms0, n - 1, m + 1);
            for r0 in res0 {
                let mut r = r0.clone();
                r.insert(0, (i, j));
                res.push(r)
            }
        }
        return res;
    }

    pub fn total_n_queens(n: i32) -> i32 {
        let n = n as usize;
        let ms = Solution::init(n);
        let res = Solution::solve(&ms, n, 0);
        return res.len() as i32;
    }
}
