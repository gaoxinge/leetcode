impl Solution {
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        }
        let d = dividend as f64 / divisor as f64;
        (if d < 0.0 { d.ceil() } else { d.floor() }) as i32
    }
}
