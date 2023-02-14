impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let len = nums.len();
        for i in 0..len {
            let mut n = nums[i];
            while !(n <= 0 || n > len as i32 || (n - 1) as usize == i || nums[(n - 1) as usize] == n) {
                nums.swap(i, (n - 1) as usize);
                n = nums[i];
            }
        }
        for i in 0..len {
            let n = nums[i];
            if (n - 1) as usize != i {
                return (i + 1) as i32;
            }
        }
        return (len + 1) as i32;
    }
}
