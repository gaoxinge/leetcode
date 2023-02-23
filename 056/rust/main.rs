use std::cmp;

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort_by_key(|a| (a[0], a[1]));
        let mut r = Vec::new();
        for b in intervals {
            if r.is_empty() {
                r.push(b.clone());
            }
            let a = r.pop().unwrap();
            if a[1] < b[0] {
                r.push(a);
                r.push(b);
            } else {
                r.push(vec![a[0], cmp::max(a[1], b[1])]);
            }
        }
        return r;
    }
}
