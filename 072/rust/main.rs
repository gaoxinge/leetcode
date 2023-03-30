use std::cmp;
use std::mem;

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        let m = word1.len();
        let n = word2.len();
        let mut result1 = vec![0; m + 1];
        let mut result2 = vec![0; m + 1];
        for i in 0..n + 1 {
            for j in 0..m + 1 {
                if i == 0 {
                    result2[j] = j;
                } else if j == 0 {
                    result2[j] = i;
                } else {
                    let a = word1[j - 1];
                    let b = word2[i - 1];
                    if a == b {
                        result2[j] = result1[j - 1];
                    } else {
                        result2[j] = cmp::min(result1[j], result1[j - 1]);
                        result2[j] = cmp::min(result2[j], result2[j - 1]);
                        result2[j] += 1;
                    }
                }
            }
            result1 = mem::replace(&mut result2, vec![0; m + 1]);
        }
        return result1[m] as i32;
    }
}
