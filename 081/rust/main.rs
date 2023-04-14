impl Solution {
    pub fn search0(nums: &Vec<i32>, target: i32, i: usize, j: usize) -> bool {
        if i + 1 >= j {
            return nums[i] == target || nums[j] == target;
        }

        let k = i + (j - i) / 2;
        if nums[k] == target || nums[i] == target || nums[j] == target {
            return true;
        }

        if nums[i] == nums[j] {
            return Solution::search0(nums, target, i, k) || Solution::search0(nums, target, k, j);
        }

        if nums[i] < nums[j] {
            return if nums[k] < target {
                Solution::search0(nums, target, k, j)
            } else {
                Solution::search0(nums, target, i, k)
            }
        }

        if nums[k] < nums[i] {
            return if nums[k] < target {
                if nums[i] < target {
                    Solution::search0(nums, target, i, k)
                } else {
                    Solution::search0(nums, target, k, j)
                }
            } else {
                Solution::search0(nums, target, i, k)
            }
        }

        return if nums[k] < target {
            Solution::search0(nums, target, k, j)
        } else {
            if nums[i] < target {
                Solution::search0(nums, target, i, k)
            } else {
                Solution::search0(nums, target, k, j)
            }
        }
    }

    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        return Solution::search0(&nums, target, 0, nums.len() - 1);
    }
}
