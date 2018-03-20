class Solution {
public:
    int myAtoi(string str) {
        int strLen = str.length();
        int newInt = 0;
        int digit = 0;
        int start = 0; // index where the first non-whitespace character appears
        int zero = '0';
        int nine = '9';
        int upperLimit = INT_MAX / 10;
        int lowerLimit = INT_MIN / 10;
        bool negative = false;
        while (true) { // to ignore whitespaces
            if (str[start] == ' ') {
                ++start;
            } else {
                break;
            }
        }
        if (str[start] == '-' || str[start] == '+') { // check if the first character is '+' or '-'
            if (str[start] == '-') {
                negative = true;
            }
            ++start;
        }
        for (int i = start; i < strLen; ++i) {
            if (str[i] >= zero && str[i] <= nine) {
                digit = str[i] - zero; // to get integer number from an ascii character
            } else {
                break;
            }
            if (newInt >= upperLimit) { // check for overflow
                return INT_MAX;
            } else if (newInt<= lowerLimit){ // checkfor overflow
                if (!(newInt == lowerLimit && digit < 9)) { // another check
                    return INT_MIN;
                }
            }
            if (negative) { // change to negative
                digit *= -1;
            }
            newInt = newInt * 10 + digit;
        }
        return newInt;
    }
};
