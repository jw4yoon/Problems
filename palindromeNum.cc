class Solution {
public:
    bool isPalindrome(int x) {
        int store = x;
        int digit = 0;
        int reverse = 0;
        if (x < 0) {
            return false;
        }
        while(store != 0) {
            digit = store % 10;
            store /= 10;
            reverse = reverse * 10 + digit;
        }
        if (x == reverse) {
            return true;
        } else {
            return false;
        }
    }
};
