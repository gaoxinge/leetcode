impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut i = -1;
        let mut j = nums.len() as i32;
        while i + 1 < j {
            let k = (i + (j - i) / 2) as usize;
            if nums[k] < target {
                i = k as i32;
            } else {
                j = k as i32;
            }
        }
        return i + 1;
    }
}
