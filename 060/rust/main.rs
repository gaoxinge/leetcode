impl Solution {
    fn frac(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        return n * Solution::frac(n - 1);
    }

    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut ms = Vec::new();
        for i in 0..n {
            ms.push(i + 1);
        }
        let mut k = k - 1;
        let mut m = Solution::frac(n);
        let mut s = String::new();
        for i in (1..n + 1).rev() {
            m /= i;
            let j = k / m;
            s = format!("{}{}", s, ms.remove(j as usize));
            k %= m;
        }
        return s;
    }
}
