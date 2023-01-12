use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut i = 0;
        let mut m = 0;
        let mut cache = HashMap::new();
        let s = s.as_bytes();
        for j in 0..s.len() {
            let c = s[j];
            while (cache.contains_key(&c)) {
                cache.remove(&s[i]);
                i += 1;
            }
            cache.insert(c, 1);
            m = std::cmp::max(m, j - i + 1);
        }
        return m as i32;
    }
}
