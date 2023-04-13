impl Solution {

    pub fn combine2(ns: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        if ns.len() < k as usize {
            return Vec::new();
        }
        if ns.len() == k as usize {
            return vec![ns];
        }
        let mut ns = ns;
        let n = ns[0];
        ns.remove(0);
        let mut result = Solution::combine2(ns.clone(), k);
        let result0 = Solution::combine2(ns.clone(), k - 1);
        for r0 in result0 {
            let mut r = r0.clone();
            r.push(n);
            result.push(r);
        } 
        return result;
    }

    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let ns: Vec<i32> = (1..n+1).collect();
        return Solution::combine2(ns, k);
    }
}
