impl Solution {
    fn longest_palindrome1(s: &String, i: usize) -> String {
        let s0 = s.as_bytes();
        let n = std::cmp::min(i, s0.len() - i - 1);
        let mut k = 0;
        for j in 1..n + 1 {
            k = j;
            if (s0[i - j] != s0[i + j]) {
                k = j - 1;
                break;
            }
        }
        return s[i - k..i + k + 1].to_string();
    }

    fn longest_palindrome2(s: &String, i: usize) -> String {
        let s0 = s.as_bytes();
        let n = std::cmp::min(i + 1, s0.len() - i - 1);
        let mut k = 0;
        for j in 1..n + 1 {
            k = j;
            if (s0[i - j + 1] != s0[i + j]) {
                k = j - 1;
                break;
            }
        }
        if k == 0 {
            return "".to_string();
        }
        return s[i - k + 1..i + k + 1].to_string();
    }

    pub fn longest_palindrome(s: String) -> String {
        let mut r = "".to_string();
        for i in 0..s.len() {
            let mut r0;
            r0 = Solution::longest_palindrome1(&s, i);
            if (r0.len() > r.len()) {
                r = r0;
            }
            r0 = Solution::longest_palindrome2(&s, i);
            if (r0.len() > r.len()) {
                r = r0;
            }
        }
        return r;
    }
}
