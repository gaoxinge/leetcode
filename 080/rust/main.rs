impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i = 1;
        let mut cnt = 1;
        for j in 1..nums.len() {
            if nums[j] == nums[i - 1] {
                if cnt == 1 {
                    nums[i] = nums[j];
                    i += 1;
                    cnt += 1;
                } else {
                    // pass
                }
            } else {
                nums[i] = nums[j];
                i += 1;
                cnt = 1;
            }
        }
        return i as i32;
    }
}
