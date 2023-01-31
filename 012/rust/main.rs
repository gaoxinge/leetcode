impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let x = vec![
            vec!["I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
            vec!["X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            vec!["C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            vec!["M", "MM", "MMM"]
        ];

        let mut n = num;
        let mut r = String::new(); 
        for i in 0..4 {
            let t = n % 10;
            if t > 0 {
                r = format!("{}{}", x[i][(t - 1) as usize], r);
            }
            n /= 10;
        }
        return r;
    }
}
