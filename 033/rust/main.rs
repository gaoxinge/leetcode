impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut i = 0;
        let mut j = nums.len();
        while i + 1 < j {
            let k = i + (j - i) / 2;
            if nums[i] < nums[k] {
                if target < nums[i] {
                    i = k;
                } else if target == nums[i] {
                    return i as i32;
                } else if target < nums[k] {
                    j = k;
                } else if target == nums[k] {
                    return k as i32;
                } else {
                    i = k;
                }
            } else {
                if target < nums[k] {
                    j = k;
                } else if target == nums[k] {
                    return k as i32;
                } else if target < nums[i] {
                    i = k;
                } else if target == nums[i] {
                    return i as i32;
                } else {
                    j = k;
                }
            }
        }
        return if nums[i] == target {i as i32} else {-1};
    }
}
