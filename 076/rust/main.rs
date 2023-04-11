use std::collections::{HashMap, HashSet};

struct Check {
    m1: HashMap<u8, usize>,
    m2: HashMap<u8, usize>,
    m3: HashSet<u8>,
}

impl Check {
    pub fn new(t: String) -> Self {
        let mut m1 = HashMap::new();
        let mut m2 = HashMap::new();
        let mut m3 = HashSet::new();
        let t = t.as_bytes();
        for c in t {
            *m1.entry(*c).or_insert(0) += 1;
            m2.entry(*c).or_insert(0);
            m3.insert(*c);
        }
        Check {
            m1,
            m2,
            m3,
        }
    }

    pub fn add(&mut self, c: &u8) {
        if !self.m1.contains_key(c) {
            return;
        }
        let m2 = self.m2.entry(*c).or_insert(0);
        let m1 = self.m1.entry(*c).or_insert(0);
        *m2 += 1;
        if m2 >= m1 {
            self.m3.remove(c);
        }
    }

    pub fn remove(&mut self, c: &u8) {
        if !self.m1.contains_key(c) {
            return;
        }
        let m2 = self.m2.entry(*c).or_insert(0);
        let m1 = self.m1.entry(*c).or_insert(0);
        *m2 -= 1;
        if m2 < m1 {
            self.m3.insert(*c);
        }
    }

    pub fn check(&self) -> bool {
        self.m3.is_empty()
    }
}

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s = s.as_bytes();
        let mut i = 0;
        let mut j = 0;
        let mut r = String::new();
        let mut check = Check::new(t);
        check.add(&s[0]);
        while j < s.len() || check.check() {
            if check.check() {
                check.remove(&s[i]);
                i += 1;
                if !check.check() {
                    if r.is_empty() || j - i + 2 < r.len() {
                        r = std::str::from_utf8(&s[i - 1..j + 1]).unwrap().to_string();
                    }
                }
            } else {
                j += 1;
                if j == s.len() {
                    continue;
                }
                check.add(&s[j]);
            }
        }
        return r;
    }
}
