impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut r = 1;
        for digit in digits.iter().rev() {
            r += digit;
            result.insert(0, r % 10);
            r /= 10;
        }
        if r > 0 {
            result.insert(0, r);
        }
        return result;
    }
}
