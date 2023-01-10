use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut cache = HashMap::new();
        for (j, b) in nums.iter().enumerate() {
            let j = j as i32;
            match cache.get(&(target - b)) {
                Some(i) => return vec![*i, j],
                None => (),
            }
            cache.insert(b, j);
        }
        return vec![];
    }
}
