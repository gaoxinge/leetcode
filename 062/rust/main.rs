impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut cache = vec![1; n];
        for i in 1..m {
            for j in 1..n {
                cache[j] += cache[j - 1]
            }
        }
        return cache[n - 1];
    }
}
