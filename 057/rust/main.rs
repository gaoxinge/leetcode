use std::cmp;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut is_push = false;
        let mut new_interval = new_interval;
        let mut result = Vec::new();
        for interval in intervals {
            if is_push || interval[1] < new_interval[0] {
                result.push(interval.clone());
            } else if new_interval[1] < interval[0] {
                result.push(new_interval.clone());
                result.push(interval.clone());
                is_push = true;
            } else {
                new_interval = vec![cmp::min(interval[0], new_interval[0]), cmp::max(interval[1], new_interval[1])];
            }
        }
        if !is_push {
            result.push(new_interval);
        }
        return result;
    }
}
