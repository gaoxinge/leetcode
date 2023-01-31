impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();

        let mut r = Vec::new();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let target = -nums[i];
            let mut j = i + 1;
            let mut k = nums.len() - 1;
            while j < k {
                let target0 = nums[j] + nums[k];
                if target0 < target {
                    j += 1;
                    while j < k {
                        if nums[j] == nums[j - 1] {
                            j += 1;
                        } else {
                            break;
                        }
                    }
                } else if target0 > target {
                    k -= 1;
                    while j < k {
                        if nums[k] == nums[k + 1] {
                            k -= 1;
                        } else {
                            break;
                        }
                    }
                } else {
                    r.push(vec![-target, nums[j], nums[k]]);
                    j += 1;
                    k -= 1;
                    while j < k {
                        if nums[j] == nums[j - 1] {
                            j += 1;
                        } else {
                            break;
                        }
                    }
                    while j < k {
                        if nums[k] == nums[k + 1] {
                            k -= 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return r;
    }
}
