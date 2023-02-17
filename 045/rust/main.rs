use std::cmp;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return 0;
        }
        let (mut k, mut m1, mut m2) = (0, 0, 1);
        loop {
            let mut m = 0;
            for i in m1..m2 {
                m = cmp::max(m, i + nums[i] as usize);
                if m >= nums.len() - 1 {
                    return (k + 1) as i32;
                }
            }
            k += 1;
            m1 = m2;
            m2 = m + 1;
        }
        return -1;
    }
}
