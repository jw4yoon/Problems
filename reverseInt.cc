class Solution {
public:
    int reverse(int x) {
        int newInt = 0;
        int digit = 0;
        while(x != 0) {
            digit = x % 10;
            x /= 10;
            if (newInt > 214748364 || newInt < -214748364) { 
                return 0;
            }
            newInt = newInt * 10 + digit;
        }
        return newInt;
    }
};
