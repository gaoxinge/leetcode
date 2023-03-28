enum Token {
    SIGN,
    DOT,
    SCIENCE,
    DIGIT,
    OTHER,
    END,
};

/*
 * INTERGER_WITHOUT_SCIENCE = [+|-]digit+
 * NUMBER_WITHOUT_SCIENCE   = [+|-]digit*[.digit*]
 * NUMBER                   = NUMBER_WITHOUT_SCIENCE[(e|E)INTERGER_WITHOUT_SCIENCE]
 */
class Solution {
public:
    Token getToken(string s, int &i) {
        if (i >= s.size()) {
            return Token::END;
        }
        char c = s[i];
        if (c == '+' || c == '-') {
            return Token::SIGN;
        } else if (c == '.') {
            return Token::DOT;
        } else if (c == 'e' || c == 'E') {
            return Token::SCIENCE;
        } else if (isdigit(c)) {
            return Token::DIGIT;
        } else {
            return Token::OTHER;
        }
    }

    bool consume(string s, int &i, Token token) {
        Token token0 = getToken(s, i);
        if (token0 == token) {
            i++;
            return true;
        }
        return false;
    }

    bool isIntegerWithoutScience(string s, int &i) {
        int n = 0;
        consume(s, i, Token::SIGN);
        while (true) {
            if (!consume(s, i, Token::DIGIT)) {
                break;
            }
            n++;
        }
        return n > 0;
    }

    bool isNumberWithoutScience(string s, int &i) {
        int n = 0;
        consume(s, i, Token::SIGN);
        while (true) {
            if (!consume(s, i, Token::DIGIT)) {
                break;
            }
            n++;
        }
        consume(s, i, Token::DOT);
        while (true) {
            if (!consume(s, i, Token::DIGIT)) {
                break;
            }
            n++;
        }
        return n > 0;
    }

    bool isNumber(string s) {
        int i = 0;
        if (!isNumberWithoutScience(s, i)) {
            return false;
        }
        if (consume(s, i, Token::SCIENCE)) {
            if (!isIntegerWithoutScience(s, i)) {
                return false;
            }
        }
        return consume(s, i, Token::END);
    }
};
