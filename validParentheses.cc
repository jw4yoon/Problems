class Solution {
public:
    bool isValid(string s) {
        int sLen = s.length();
        if (sLen % 2 != 0) { // for better runtime
            return false;
        }
        string left;
        for (int i = 0; i < sLen; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                left.push_back(s[i]);
            } else if (s[i] == ')') {
                if (left.back() == '(') {
                    left.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (left.back() == '{') {
                    left.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (left.back() == '[') {
                    left.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (left == "") { //if all parentheses are properly closed, it is valid
            return true;
        } else {
            return false;
        }
    }
};
