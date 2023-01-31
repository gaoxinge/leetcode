impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();

        let mut r = nums[0] + nums[1] + nums[2] - target;
        for i in 0..nums.len() {
            let t = nums[i];
            let mut j = i + 1;
            let mut k = nums.len() - 1;
            while j < k {
                let t0 = t + nums[j] + nums[k] - target;
                if t0.abs() < r.abs() {
                    r = t0;
                }                
                if t0 < 0 {
                    j += 1;
                } else if t0 > 0 {
                    k -= 1;
                } else {
                    return target;
                }
            }
        }
        return r + target;

    }
}
