impl Solution {
    fn search_range1(nums: &Vec<i32>, target: i32) -> i32 {
        let mut i = -1;
        let mut j = nums.len() as i32;
        while i + 1 < j {
            let k = (i + (j - i) / 2) as usize;
            if nums[k] < target {
                i = k as i32;
            } else {
                j = k as i32;
            }
        }
        return i;
    }

    fn search_range2(nums: &Vec<i32>, target: i32) -> i32 {
        let mut i = -1;
        let mut j = nums.len() as i32;
        while i + 1 < j {
            let k = (i + (j - i) / 2) as usize;
            if nums[k] <= target {
                i = k as i32;
            } else {
                j = k as i32;
            }
        }
        return j;
    }

    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let i = Solution::search_range1(&nums, target);
        let j = Solution::search_range2(&nums, target);
        if i + 1 == j {
            return vec![-1, -1];
        } else {
            return vec![i + 1, j -1];
        }
    }
}
