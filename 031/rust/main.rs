impl Solution {
    pub fn reverse(nums: &mut Vec<i32>, i: usize) {
        let n = nums.len();
        let m = nums.len() - i;
        for j in 0..m / 2 {
            nums.swap(i + j, n - 1 - j);
        }
    }

    pub fn swap(nums: &mut Vec<i32>, i: usize) -> bool {
        if i == nums.len() - 1 {
            return false;
        }
        if Solution::swap(nums, i + 1) {
            return true;
        }
        let mut r = false;
        for j in (i + 1..nums.len()).rev() {
            if nums[j] > nums[i] {
                nums.swap(i, j);
                r = true;       
                break;
            }
        }
        if !r {
            return false;
        }
        Solution::reverse(nums, i + 1);
        return true;
    }

    pub fn next_permutation(nums: &mut Vec<i32>) {
        let r = Solution::swap(nums, 0);
        if !r {
            nums.reverse();
        }
    }
}
