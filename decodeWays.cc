class Solution {
public:
    int numDecodings(string s) {
        int sLen = s.length();
        if (sLen == 0 || (sLen > 0 && s[0] == '0')) {
            return 0;
        }
        for (int i = 0; i < sLen - 1; ++i) {
            if ((s[i] == '1' || s[i] == '2') && s[i+1] == '0') { // modify 10 and 20 to f
                s[i] = 'f'; // 'f' means flag
                s = s.substr(0, i+1) + s.substr(i+2); // exclude a char (since we've changed 10 or 20 to f)
                --i; //start again from 'f'
            } else if (s[i+1] == '0') {
                return 0;
            }
        }
        int result = 0;
        int twoBeforeResult = 1;
        int oneBeforeResult = 1;
        char charPrev;
        sLen = s.length();
        for (int i = 0; i < sLen; ++i) {
            if (i == 0) {
                charPrev = s[i];
            } else if (i == 1) {
                if (s[i] != 'f' && (charPrev == '1' || (charPrev == '2' && s[i] <= '6'))) {
                    result = twoBeforeResult + oneBeforeResult;
                    oneBeforeResult = result;
                } else {
                    result = oneBeforeResult;
                }
                charPrev = s[i];
            } else {
                if (s[i] != 'f' && (charPrev == '1' || (charPrev == '2' && s[i] <= '6'))) {
                    result = twoBeforeResult + oneBeforeResult;
                    twoBeforeResult = oneBeforeResult;
                    oneBeforeResult = result;
                } else {
                    twoBeforeResult = oneBeforeResult;
                }
                charPrev = s[i];
            }
        }
        return oneBeforeResult;
    }
};
