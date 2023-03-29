impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut a = 1;
        let mut b = 1;
        for _ in 1..n {
            let t = a + b;
            a = b;
            b = t;
        }
        return b;
    }
}
