impl Solution {
    pub fn permute0(nums: &Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        if n == 0 {
            return vec![Vec::new()];
        }

        let mut res = Vec::new();
        for i in 0..n {
            let t = nums[i];
            let mut nums0 = nums.clone();
            nums0.remove(i);
            let res0 = Solution::permute0(&nums0);
            for r0 in res0 {
                let mut r = r0.clone();
                r.insert(0, t);
                res.push(r);
            }
        }
        return res;
    }

    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        return Solution::permute0(&nums);
    }
}
