class Solution {
public:
    string longestPalindrome(string s) {
        string longestPal = "";
        int count = 1;
        int length = s.length();
        string storeOdd = ""; // odd palindrome
        string storeEven = ""; // even palindrome
        if (length == 1) {
            return s;
        }
        for (int i = 0; i < length; i++) {
            storeOdd = s.substr(i, 1); // get one letter
            for (int j = i; j < length; j++) {
                if (i - count >= 0 && (i + count) < length && s[i-count] == s[i + count]) { // check if left and right chars of a substring are the same
                    storeOdd = s.substr(i-count, count * 2 + 1);
                    ++count;
                } else {
                    break;
                }
                
            }
            if (longestPal.length() < storeOdd.length()) {
                longestPal = storeOdd;
            }
            count = 1;
            
            if (i != 0 && s[i] == s[i-1]) {
                storeEven = s.substr(i-1,2); // get two letters
                for (int j = i; j < length; j++) {
                    if (i-1 - count >= 0 && (i + count) < length && s[i-1-count] == s[i + count]) { // check if left and right chars of a substring are the same
                        ++count;
                        storeEven = s.substr(i-count, count * 2);
                    } else {
                        break;
                    }
                }
                if (longestPal.length() < storeEven.length()) {
                    longestPal = storeEven;
                }
                count = 1;
            }
        }
        return longestPal;
    }
};
