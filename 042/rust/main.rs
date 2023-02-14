use std::cmp;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut j = height.len() - 1;
        let mut maxLeft = 0;
        let mut maxRight = 0;
        let mut n = 0;
        while i < j {
            if height[i] < height[j] {
                maxLeft = cmp::max(maxLeft, height[i]);
                n += maxLeft - height[i];
                i += 1;
            } else {
                maxRight = cmp::max(maxRight, height[j]);
                n += maxRight - height[j];
                j -= 1;
            }
        }
        return n;
    }
}
