impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if (num_rows == 1) {
            return s;
        }

        let s = s.as_bytes();
        let n = s.len();
        let num_rows = num_rows as usize;
        let m = n / (num_rows - 1) + 1;
        let mut r = String::from("");
        let mut index;
        let mut insert;
        for i in 0..num_rows {
            for j in 0..m {
                if j % 2 == 0 {
                    index = j * (num_rows - 1) + i;
                    insert = i != num_rows - 1;
                } else {
                    index = j * (num_rows - 1) + (num_rows - 1 - i);
                    insert = i != 0;
                }
                if index < n && insert {
                    r.push(s[index] as char);
                }
            }
        }
        return r;
    }
}
