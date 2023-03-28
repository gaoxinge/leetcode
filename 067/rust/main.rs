impl Solution {
    pub fn binary_add(r: char, c1: char, c2: char) -> Vec<char> {
        if r == '0' && c1 == '0' && c2 == '0' {
            return vec!['0', '0'];
        }
        if r == '0' && c1 == '0' && c2 == '1' {
            return vec!['0', '1'];
        }
        if r == '0' && c1 == '1' && c2 == '0' {
            return vec!['0', '1'];
        }
        if r == '0' && c1 == '1' && c2 == '1' {
            return vec!['1', '0'];
        }
        if r == '1' && c1 == '0' && c2 == '0' {
            return vec!['0', '1'];
        }
        if r == '1' && c1 == '0' && c2 == '1' {
            return vec!['1', '0'];
        }
        if r == '1' && c1 == '1' && c2 == '0' {
            return vec!['1', '0'];
        }
        if r == '1' && c1 == '1' && c2 == '1' {
            return vec!['1', '1'];
        }
        return Vec::new();
    }

    pub fn add_binary(a: String, b: String) -> String {
        let a = a.as_bytes();
        let b = b.as_bytes();
        let mut s = String::new();
        let mut r = '0';
        let mut i = 1;
        while i <= a.len() || i <= b.len() {
            let c1 = if i <= a.len() {a[a.len() - i] as char}  else {'0'};
            let c2 = if i <= b.len() {b[b.len() - i] as char}  else {'0'};
            let p = Solution::binary_add(r, c1, c2);
            s = format!("{}{}", p[1], s);
            r = p[0];
            i += 1;
        }
        if (r != '0') {
            s = format!("{}{}", r, s);
        }
        return s;
    }
}
