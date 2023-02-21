use std::cmp;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut t = 0;
        let mut m = nums[0];
        for num in nums {
            t += num;
            if t > 0 {
                m = cmp::max(m, t);
            } else {
                m = cmp::max(m, num);
                t = 0;
            }
        }
        return m;
    }
}
