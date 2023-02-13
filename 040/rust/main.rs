impl Solution {
    fn solve(candidates: &Vec<i32>, target: i32, i: usize) -> Vec<Vec<i32>> {
        if target == 0 {
            return vec![vec![]];
        }
        if i >= candidates.len() {
            return Vec::new();
        }
        let mut res = Vec::new();
        for j in i..candidates.len() {
            if j > i && candidates[j] == candidates[j - 1] {
                continue;
            }
            let c = candidates[j];
            if target < c {
                continue;
            }
            let res0 = Solution::solve(candidates, target - c, j + 1);
            for re0 in res0 {
                let mut re = re0.clone();
                re.insert(0, c);
                res.push(re);
            }
        }
        return res;
    }

    pub fn combination_sum2(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut candidates = candidates;
        candidates.sort();
        return Solution::solve(&candidates, target, 0);
    }
}
