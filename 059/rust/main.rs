impl Solution {
    pub fn init(n: usize) -> Vec<Vec<i32>> {
        let mut ms = Vec::new();
        for i in 0..n {
            let mut m = Vec::new();
            for j in 0..n {
                m.push(0);
            }
            ms.push(m);
        }
        return ms;
    }

    pub fn gen(ms: &mut Vec<Vec<i32>>, k: usize, n: usize, v: i32) {
        if n == 0 {
            return;
        }
        if n == 1 {
            ms[k][k] = v;
            return;
        }
        let mut v = v;
        // top
        for j in k..k + n - 1 {
            ms[k][j] = v;
            v += 1;
        }
        // right
        for i in k..k + n - 1 {
            ms[i][k + n - 1] = v;
            v += 1;
        }
        // bottom
        for j in (k + 1..k + n).rev() {
            ms[k + n - 1][j] = v;
            v += 1;
        }
        // left
        for i in (k + 1..k + n).rev() {
            ms[i][k] = v;
            v += 1;
        }
        Solution::gen(ms, k + 1, n - 2, v);
    }

    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut ms = Solution::init(n as usize);
        Solution::gen(&mut ms, 0, n as usize, 1);
        return ms;
    }
}
