impl Solution {
    fn g1(s: String) -> Vec<String> {
        let mut i = 0;
        let mut r = Vec::new();
        let b = s.as_bytes();
        for j in 0..b.len() {
            if b[j] != b[i] {
                r.push((&s[i..j]).to_string());
                i = j;
            }
        }
        r.push((&s[i..b.len()]).to_string());
        return r;
    }

    fn g2(s: String) -> String {
        let r = Solution::g1(s);
        let mut res = String::new();
        for c in r {
            res += &format!("{}{}", c.len(), c.chars().nth(0).unwrap());
        }
        return res;
    }

    pub fn count_and_say(n: i32) -> String {
        let mut m = "1".to_string();
        for i in 1..n {
            m = Solution::g2(m);
        }
        return m;
    }
}
