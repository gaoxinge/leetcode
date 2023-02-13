impl Solution {
    fn solve(candidates: &Vec<i32>, target: i32, i: usize) -> Vec<Vec<i32>> {
        if i >= candidates.len() {
            return if target != 0 { Vec::new() } else { vec![vec![]] }
        }

        let c = candidates[i];
        let r = target / c;
        let mut res = Vec::new();
        for k in 0..r + 1 {
            let res0 = Solution::solve(candidates, target - k * c, i + 1);
            for re0 in res0 {
                let mut re = re0.clone();
                for n in 0..k {
                    re.insert(0, c);
                }
                res.push(re);
            }
        }
        return res;
    }

    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        return Solution::solve(&candidates, target, 0);
    }
}
