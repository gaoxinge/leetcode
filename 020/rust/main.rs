impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut v = Vec::new();
        let s = s.as_bytes();
        for c in s {
            let t = *c as char;
            match t {
                '(' | '[' | '{' => v.push(t),
                ')' | ']' | '}' => {
                    if let Some(t0) = v.pop() {
                       if (t0 == '(' && t == ')') || (t0 == '[' && t == ']') || (t0 == '{' && t == '}') {
                           continue;
                       } 
                    }  
                    return false;
                }
                _ => (),
            }
        }
        return v.is_empty();
    }
}
