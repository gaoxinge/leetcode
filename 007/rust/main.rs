impl Solution {
    pub fn sign(x: i32) -> i32 {
        if x >= 0 { 1 } else { -1 }
    }

    pub fn abs(x: i32) -> i32 {
        if x >= 0 { x } else { -x }
    }

    pub fn preCheck(r: i32, r0: i32) -> bool {
        r > 214748364 || (r == 214748364 && r0 > 7)
    }

    pub fn reverse(x: i32) -> i32 {
        if x == -2147483648 {
            return 0;
        }

        let s = Solution::sign(x);
        let mut x = Solution::abs(x);
        let mut r = 0;
        while x > 0 {
            let r0 = x % 10;
            if Solution::preCheck(r, r0) {
                return 0;
            }
            r *= 10;
            r += r0;
            x /= 10;
        }

        return s * r;
    }
}
