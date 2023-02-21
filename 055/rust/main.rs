use std::cmp;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut m1 = -1;
        let mut m2 = 0;
        let mut m = 0;
        loop {
            for i in m1 + 1..m2 + 1 {
                m = cmp::max(m, i + nums[i as usize]);
                if m >= nums.len() as i32 - 1 {
                    return true;
                }
            }
            if m == m2 {
                return false;
            }
            m1 = m2;
            m2 = m;
        }
        return false;
    }
}
