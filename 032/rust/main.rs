use std::cmp;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut m = 0;
        let mut stack = Vec::new();
        let mut k = -1;
        let s = s.as_bytes();
        for i in 0..s.len() {
            let c = s[i] as char;
            if c == '(' {
                stack.push(i as i32);
            } else {
                if stack.is_empty() {
                    k = i as i32;
                    continue;
                }
                stack.pop();
                let j = if !stack.is_empty() { *stack.last().unwrap() } else { k };
                m = cmp::max(m, (i as i32) - j); 
            }
        }
        return m;
    }
}
