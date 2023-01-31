impl Solution {
    pub fn is_same(bss: &Vec<&[u8]>, i: usize) -> bool {
        if bss.is_empty() {
            return false;
        }
        
        for bs in bss {
            if bs.len() <= i {
                return false;
            }
        }

        let t = bss[0][i];
        for bs in bss {
            if bs[i] != t {
                return false;
            }
        }
        
        return true;
    }

    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut s = String::new();
        let bss: Vec<_> = strs.iter().map(|b| b.as_bytes()).collect();
        for i in 0..200 {
            if !Solution::is_same(&bss, i) {
                return s;
            }
            s.push(bss[0][i] as char);
        }
        return s;
    }
}
