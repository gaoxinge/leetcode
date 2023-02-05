impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut k = 0;
        for i in 1..nums.len() {
            if nums[i] == nums[k] {
                continue;
            }
            k += 1;
            nums[k] = nums[i];
        }
        return (k + 1) as i32;
    }
}
