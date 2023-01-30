impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut j = height.len() - 1;
        let mut m = 0;
        while i < j {
            let m0 = (j - i) as i32 * std::cmp::min(height[i], height[j]);
            m = std::cmp::max(m, m0);
            if height[i] <= height[j] {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return m;
    }
}
