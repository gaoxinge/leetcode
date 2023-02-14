use std::cmp;

impl Solution {
    fn multiply1(num1: &[u8], p: u8) -> String {
        let p = (p as char).to_digit(10).unwrap();
        let mut q = 0;
        let mut s = String::new();
        for b in num1.iter().rev() {
            let c = (*b as char).to_digit(10).unwrap();
            q += c * p; 
            s = format!("{}{}", q % 10, s);
            q /= 10; 
        }
        if q > 0 {
            s = format!("{}{}", q, s);
        }
        return s;
    }

    fn multiply2(num1: &[u8], num2: &[u8]) -> String {
        let p = num2[num2.len() - 1];
        let s2 = Solution::multiply1(num1, p);
        if num2.len() == 1 {
            return s2;
        }
        let s1 = Solution::multiply2(num1, &num2[0..num2.len() - 1]);
        let s1 = format!("{}0", s1);
        return Solution::add(s1.as_bytes(), s2.as_bytes());
    }

    fn add(num1: &[u8], num2: &[u8]) -> String {
        let n1 = num1.len();
        let n2 = num2.len();
        let n = cmp::max(n1, n2);
        let mut q = 0;
        let mut s = String::new();
        for i in 0..n {
            let j1 = num1.len() - 1 - i;
            let j2 = num2.len() - 1 - i;
            let a = if n1 >= i + 1 { (num1[n1 - 1 - i] as char).to_digit(10).unwrap() } else { 0 };
            let b = if n2 >= i + 1 { (num2[n2 - 1 - i] as char).to_digit(10).unwrap() } else { 0 };
            q += a + b;
            s = format!("{}{}", q % 10, s);
            q /= 10;
        }
        if q > 0 {
            s = format!("{}{}", q, s);
        }
        return s;
    }

    pub fn multiply(num1: String, num2: String) -> String {
        let zero = "0".to_string();
        if num1 == zero || num2 == zero {
            return zero;
        }
        let num1 = num1.as_bytes();
        let num2 = num2.as_bytes();
        return Solution::multiply2(num1, num2);
    }
}
