impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut i = 0;
        let mut j = nums.len() - 1;
        let mut k = 0;
        while i <= k && k <= j {
            while i <= k && k <= j {
                let n = nums[k];
                if n == 0 {
                    nums.swap(i, k);
                    i += 1;
                } else if n == 2 {
                    nums.swap(k, j);
                    if j == 0 {
                        return;
                    }
                    j -= 1;
                } else {
                    break;
                }
            }
            k += 1;
        }
    }
}
