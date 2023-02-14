impl Solution {
    fn split(p: &Vec<char>) -> Vec<Vec<char>> {
        let mut r = Vec::new();
        let mut s = Vec::new();
        for i in 0..p.len() {
            if p[i] != '*' {
                s.push(p[i]);
                continue;
            }
            if !s.is_empty() {
                r.push(s.clone());
            }
            s = vec![];
        }
        if !s.is_empty() {
            r.push(s.clone());
        }
        return r;
    }

    fn startsWith(s: &Vec<char>, p: &Vec<char>, pos: usize) -> bool {
        if s.len() < p.len() + pos {
            return false;
        }
        for i in 0..p.len() {
            let c1 = s[pos + i];
            let c2 = p[i];
            if (c2 != '?' && c1 != c2) {
                return false;
            }
        }
        return true;
    }

    fn endsWith(s: &Vec<char>, p: &Vec<char>, pos: usize) -> bool {
        if s.len() < p.len() + pos {
            return false;
        }
        for i in 0..p.len() {
            let c1 = s[s.len() - 1 - i];
            let c2 = p[p.len() - 1 - i];
            if (c2 != '?' && c1 != c2) {
                return false;
            }
        }
        return true;
    }

    fn match0(s: &Vec<char>, p: &Vec<char>, pos: usize) -> bool {
        if s.len() != p.len() + pos {
            return false;
        }
        return Solution::startsWith(s, p, pos);
    }

    fn find(s: &Vec<char>, p: &Vec<char>, pos: usize) -> Option<usize> {
        if s.len() < p.len() + pos {
            return None;
        }
        for i in pos..s.len() - p.len() + 1 {
            if Solution::startsWith(s, p, i) {
                return Some(i);
            }
        }
        return None;
    }

    pub fn is_match(s: String, p: String) -> bool {
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();
        if p.is_empty() {
            return s.is_empty();
        }
        
        let mut pos = 0;
        let ps = Solution::split(&p);
        for i in 0..ps.len() {
            let isStart = i == 0 && p[0] != '*';
            let isEnd = i == ps.len() - 1 && p[p.len() - 1] != '*';
            if isStart && isEnd {
                return Solution::match0(&s, &ps[i], pos);
            }
            if isEnd {
                return Solution::endsWith(&s, &ps[i], pos);
            }
            let pos0 = Solution::find(&s, &ps[i], pos);
            if pos0.is_none() {
                return false;
            }
            pos = pos0.unwrap();
            if isStart {
                if pos != 0 {
                    return false; 
                }
            }
            pos += ps[i].len();
        }
        return true;
    }
}
