impl Solution {

    pub fn pre_check1(r: u32, r0: u32) -> bool {
         r > 214748364 || (r == 214748364 && r0 > 7)
    }

    pub fn pre_check2(r: u32, r0: u32) -> bool {
         r > 214748364 || (r == 214748364 && r0 >= 8)
    }

    pub fn pre_check(r: u32, r0: u32, sign: i32) -> bool {
        if sign > 0 { Solution::pre_check1(r, r0) } else { Solution::pre_check2(r, r0) }
    }

    pub fn pre_return(sign: i32) -> i32 {
        if sign > 0 { 2147483647 } else { -2147483648 }
    }

    pub fn is_alpha(c: char) -> bool {
        c.is_alphabetic() || c == '.'
    }

    pub fn my_atoi(s: String) -> i32 {
        let mut sign = 1;
        let mut r = 0;
        let mut start = false;
        for c in s.chars() {
            let isDigit = c.is_digit(10);

            if ((!start && Solution::is_alpha(c)) || (start && !isDigit)) {
                break;
            }

            if (!start) {
                if (c == '+') {
                    sign = 1;
                    start = true;
                    continue;
                } else if (c == '-') {
                    sign = -1;
                    start = true;
                    continue;
                } else if (isDigit) {
                    start = true;
                } else {
                    continue;
                }
            }

            let r0 = c.to_digit(10).unwrap();
            if Solution::pre_check(r, r0, sign) {
                return Solution::pre_return(sign);
            }
            r *= 10;
            r += r0;
        }
        return sign * r as i32;
    }
}
