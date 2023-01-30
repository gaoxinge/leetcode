impl Solution {
    pub fn parse(p: String) -> Vec<String> {
        let mut ps = Vec::new();
        let mut s = "".to_string();
        for c in p.chars() {
            if s == "" {
                s = c.to_string();
                continue;
            }
            if c == '*' {
                s.push(c);
                ps.push(s);
                s = "".to_string();
            } else {
                ps.push(s);
                s = c.to_string();
            }
        }
        if s != "" {
            ps.push(s);
        }
        return ps;
    }

    pub fn simplify(ps: Vec<String>) -> Vec<String> {
        let mut ps0 = Vec::new();
        if ps.is_empty() {
            return ps0;
        }
        let mut p = ps[0].clone();
        for i in 1..ps.len() {
            if ps[i] == p && p != ".*" && p.len() > 1 {
                continue;
            }
            ps0.push(p);
            p = ps[i].clone();
        }
        ps0.push(p);
        return ps0;
    }

    pub fn is_match0(s: String, p: String) -> bool {
        if p == ".*" {
            return true;
        } 
        if p.len() > 1 {
            let c = p.as_bytes()[0] as char;
            for c0 in s.chars() {
                if c0 != c {
                    return false;
                }
            }
            return true;
        }
        if p == "." {
            return s.len() == 1;
        }
        return s == p;
    }

    pub fn is_match1(s: String, ps: &Vec<String>, k: usize) -> bool {
        if (k >= ps.len()) {
            return s.is_empty();
        }
        for i in 0..s.len() + 1 {
            let s1 = s[0..i].to_string();
            if !Solution::is_match0(s1, ps[k].clone()) {
                if (i == 0) {
                    continue;
                }
                return false;
            }
            let s2 = s[i..s.len()].to_string();
            if Solution::is_match1(s2, ps, k + 1) {
                return true;
            }
        }
        return false;
    }

    pub fn is_match(s: String, p: String) -> bool {
        let ps = Solution::simplify(Solution::parse(p));
        return Solution::is_match1(s, &ps, 0);
    }
}
