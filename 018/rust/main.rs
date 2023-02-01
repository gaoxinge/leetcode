impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut r = Vec::new();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            for j in i + 1..nums.len() {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }
                let t = target as i64 - nums[i] as i64 - nums[j] as i64;
                let mut k = j + 1;
                let mut l = nums.len() - 1;
                while k < l {
                    let t0 = nums[k] as i64 + nums[l] as i64;
                    if t0 < t {
                        k += 1;
                    } else if t0 > t {
                        l -= 1;
                    } else {
                        r.push(vec![nums[i], nums[j], nums[k], nums[l]]);
                        k += 1;
                        l -= 1;
                        while k < l && nums[k] == nums[k - 1]{
                            k += 1;
                        }
                        while k < l && nums[l] == nums[l + 1] {
                            l -= 1;
                        }
                    }
                }
            }
        }
        return r;
    }
}
