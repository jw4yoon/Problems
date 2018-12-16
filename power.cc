class Solution {
public:
    double myPow(double x, int n) {
        //implement x^n
        double result = x;
        int extraIteration = 0;
        bool intMin = false;
        if (n == 0 || x == 1) {
            result = 1;
            return result;
        } else if (x == -1) {
            if (n % 2 == 0) {
                return 1;
            } else {
                return -1;
            }
        }
        if (n < 0) {
            extraIteration = 2;
        }
        if (n == INT_MIN) {
            intMin = true;
            n += 1; // to make abs(n) to not cause overflow
            extraIteration+=1;
        }
        for (int i = 1; i < abs(n); ++i) {
            if (result == 0) {
                return result;
            } else if (n > 0) {
                result *= x;
            } else if (n < 0) {
                result /= x;
            }
        }
        for (int i = 0; i < extraIteration; ++i) {
            if (result == 0) {
                return result;
            } else if (n > 0) {
                result *= x;
            } else if (n < 0) {
                result /= x;
            }
        }
        
        return result;
    }
};
