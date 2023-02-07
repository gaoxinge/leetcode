use std::collections::HashMap;

impl Solution {
    fn slide(s: &str, cnt0: &mut HashMap<String, usize>, wordLen: usize, totalLen: usize, start: usize) -> Vec<usize> {
        let mut cnt = HashMap::new();
        let (mut i, mut j) = (start, start);
        let mut res = Vec::new();
        while j < s.len() - wordLen + 1 {
            let word = &s[j..j + wordLen];
            let t0 = cnt0.entry(word.to_string()).or_insert(0);
            if (*t0 == 0) {
                cnt.clear();
                i = j + wordLen;
                j += wordLen;
                continue;
            }
            while *cnt.entry(word).or_insert(0) == *t0 {
                let word1 = &s[i..i + wordLen];
                *cnt.entry(word1).or_insert(0) -= 1;
                i += wordLen;
            }
            *cnt.entry(word).or_insert(0) += 1;
            if j - i + wordLen == totalLen {
                res.push(i);
            }
            j += wordLen;
        }
        return res;
    }

    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let wordLen = words[0].len();
        let totalLen = words.len() * wordLen;
        let mut cnt0 = HashMap::new();
        for word in words {
            *cnt0.entry(word).or_insert(0) += 1;
        }

        let mut ress = Vec::new();
        for start in 0..wordLen {
            let res = Solution::slide(&s, &mut cnt0, wordLen, totalLen, start);
            for r in res {
                ress.push(r as i32);
            }
        }
        return ress;
    }
}
