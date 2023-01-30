impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x == 0 {
            return true;
        }
        if x < 0 || x % 10 == 0 {
            return false;
        }
        let mut x0 = -1;
        let mut x = x;
        let mut y = 0;
        while x > y {
            y *= 10;
            y += x % 10;
            x0 = x;
            x /= 10;
        }
        return y == x || y == x0;
    }
}
