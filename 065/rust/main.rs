#[derive(Debug,PartialEq)]
enum Token {
    SIGN,
    DOT,
    SCIENCE,
    DIGIT,
    OTHER,
    EOF,
}

impl Solution {
    pub fn get_token(s: &[u8], i: &mut usize) -> Token {
        if *i >= s.len() {
            return Token::EOF;
        }
        let c = s[*i] as char;
        if c == '+' || c == '-' {
            return Token::SIGN;
        } else if c == '.' {
            return Token::DOT;
        } else if c == 'e' || c == 'E' {
            return Token::SCIENCE;
        } else if c.is_digit(10) {
            return Token::DIGIT;
        }
        return Token::OTHER;
    }

    pub fn consume(s: &[u8], i: &mut usize, token: Token) -> bool {
        let token0 = Solution::get_token(s, i);
        if token0 == token {
            *i += 1;
            return true;
        }
        return false;
    }

    pub fn is_integer_without_science(s: &[u8], i: &mut usize) -> bool {
        let mut n = 0;
        Solution::consume(s, i, Token::SIGN);
        loop {
            if !Solution::consume(s, i, Token::DIGIT) {
                break;
            }
            n += 1;
        }
        return n > 0;
    }

    pub fn is_number_without_science(s: &[u8], i: &mut usize) -> bool {
        let mut n = 0;
        Solution::consume(s, i, Token::SIGN);
        loop {
            if !Solution::consume(s, i, Token::DIGIT) {
                break;
            }
            n += 1;
        }
        Solution::consume(s, i, Token::DOT);
        loop {
            if !Solution::consume(s, i, Token::DIGIT) {
                break;
            }
            n += 1;
        }
        return n > 0;
    }

    pub fn is_number(s: String) -> bool {
        let s = s.as_bytes();
        let mut i = 0;
        if !Solution::is_number_without_science(s, &mut i) {
            return false;
        }
        if Solution::consume(s, &mut i, Token::SCIENCE) {
            if !Solution::is_integer_without_science(s, &mut i) {
                return false;
            }
        }
        return Solution::consume(s, &mut i, Token::EOF);
    }
}
