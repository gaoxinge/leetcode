impl Solution {
    pub fn to_string(results: Vec<&str>) -> Vec<String> {
        results.iter().map(|c| c.to_string()).collect()
    } 

    pub fn letter_combinations0(digits: &[char]) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }
        if digits.len() == 1 {
            match digits[0] {
                '2' => return Solution::to_string(vec!["a", "b", "c"]),
                '3' => return Solution::to_string(vec!["d", "e", "f"]),
                '4' => return Solution::to_string(vec!["g", "h", "i"]),
                '5' => return Solution::to_string(vec!["j", "k", "l"]),
                '6' => return Solution::to_string(vec!["m", "n", "o"]),
                '7' => return Solution::to_string(vec!["p", "q", "r", "s"]),
                '8' => return Solution::to_string(vec!["t", "u", "v"]),
                '9' => return Solution::to_string(vec!["w", "x", "y", "z"]),
                _ => (),
            }
        }
        let r1 = Solution::letter_combinations0(&digits[0..1]);
        let r2 = Solution::letter_combinations0(&digits[1..]);
        let mut r = Vec::new();
        for s1 in r1.iter() {
            for s2 in r2.iter() {
                r.push(s1.clone() + &(s2.clone()));
            }
        }
        return r;
    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        let digits: Vec<_> = digits.as_bytes().iter().map(|c| *c as char).collect();
        Solution::letter_combinations0(&digits)
    }
}
