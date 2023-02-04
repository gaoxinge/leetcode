impl Solution {
    pub fn f(left: i32, right: i32) -> Vec<String> {
        if left == 0 {
            return vec![")".repeat(right as usize)];
        }
        
        let mut r = Vec::new();
        
        let r0 = Solution::f(left - 1, right + 1);
        for s in r0 {
            r.push(format!("({s}"));
        }

        if (right > 0) {
            let r0 = Solution::f(left, right - 1);
            for s in r0 {
                r.push(format!("){s}"));
            }
        }

        return r;
    }

    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        return Solution::f(n, 0);
    }
}
