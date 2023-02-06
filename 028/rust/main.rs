impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if let Some(t) = &haystack.find(&needle) {*t as i32} else {-1}
    }
}
