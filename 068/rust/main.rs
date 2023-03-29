use std::cmp;

impl Solution {
    fn get_line(line: Vec<String>, cnt: usize, max_width: usize, last: bool) -> String {
        let mut space_width1 = 1;
        let mut space_width2 = 1;
        let mut k = 0;
        if !last {
            let m = max_width - cnt;
            let n = cmp::max(line.len() - 1, 1);
            k = m % n;
            space_width2 = m / n;
            space_width1 = space_width2 + 1;
        }
        let space1 = " ".repeat(space_width1);
        let space2 = " ".repeat(space_width2);
        let mut s = line[0].clone();
        for i in 1..line.len() {
            let word = line[i].clone();
            if i <= k {
                s = format!("{}{}{}", s, space1, word);
            } else {
                s = format!("{}{}{}", s, space2, word);
            }
        }
        s = format!("{}{}", s, " ".repeat(max_width - s.len()));
        return s;
    }

    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let max_width = max_width as usize;
        let mut cnt1 = words[0].len();
        let mut cnt2 = words[0].len();
        let mut line = vec![words[0].clone()];
        let mut result = Vec::new();
        for i in 1..words.len() {
            let word = words[i].clone();
            if cnt1 + 1 + word.len() <= max_width {
                cnt1 += 1 + word.len();
                cnt2 += word.len();
                line.push(word);
            } else {
                result.push(Solution::get_line(line, cnt2, max_width, false));
                cnt1 = word.len();
                cnt2 = word.len();
                line = vec![word];
            }
        }
        result.push(Solution::get_line(line, cnt2, max_width, true));
        return result;
    }
}
