impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.is_empty() {
            return vec![vec![]];
        }
        let mut nums = nums;
        let n = nums.pop().unwrap();
        let mut result = Solution::subsets(nums);
        let size = result.len();
        for i in 0..size {
            let mut r = result[i].clone();
            r.push(n);
            result.push(r);
        }
        return result;
    }
}
