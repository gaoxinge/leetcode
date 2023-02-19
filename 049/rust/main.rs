use std::collections::HashMap;

impl Solution {
    fn generate(str: &String) -> String {
        let mut m = HashMap::new();
        let str = str.as_bytes();
        for b in str {
            let t = m.entry(b).or_insert(0);
            *t += 1
        }
        let mut s = String::new();
        for b in "abcdefghijklmnopqrstuvwxyz".as_bytes() {
            let t = m.entry(b).or_insert(0);
            s += &(*t).to_string();
            s += ":"
        }
        return s;
    }

    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut groups = HashMap::new();
        for str in strs {
            let key = Solution::generate(&str);
            let t = groups.entry(key).or_insert(Vec::new());
            (*t).push(str.clone());
        }
        let mut res = Vec::new();
        for (k, v) in groups {
            res.push(v);
        }
        return res;
    }
}
