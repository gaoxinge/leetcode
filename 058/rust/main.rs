impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut cnt = 0;
        let s = s.as_bytes();
        for i in (0..s.len()).rev() {
            let c = s[i] as char;
            if c != ' ' {
                cnt += 1;
            } else if cnt > 0 {
                break;
            }
        }
        return cnt;
    }
}
