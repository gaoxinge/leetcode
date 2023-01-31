impl Solution {
    pub fn get_char(c: char) -> i32 {
        if c == 'I' {
            return 1;
        }
        if c == 'V' {
            return 5;
        }
        if c == 'X' {
            return 10;
        }
        if c == 'L' {
            return 50;
        }
        if c == 'C' {
            return 100;
        }
        if c == 'D' {
            return 500;
        }
        return 1000;
    }

    pub fn roman_to_int(s: String) -> i32 {
        let mut v0 = 0;
        let mut v1 = 0;
        let mut r = 0;
        let s = s.as_bytes();
        for i in 0..s.len() {
            let c = s[s.len() - 1 - i] as char;
            v1 = Solution::get_char(c);
            if (v1 < v0) {
                r -= v1;
            } else {
                r += v1;
            }
            v0 = v1;
        }
        return r;
    }
}
