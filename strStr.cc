class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length();
        int needleLen = needle.length();
        bool startingCheck = false;
        bool interrupted = false;
        if  (needle == "") {
            return 0;
        }
        if (haystackLen < needleLen) {
            return -1;
        }
        for (int i = 0; i < haystackLen; ++i) {
            for (int j = 0; j < needleLen; ++j) {
                if (haystack[i] == needle[0]) {
                    startingCheck = true;
                }
                if (i+j > haystackLen || (startingCheck && haystack[i+j] != needle[j])) {
                    interrupted = true;
                    break;
                }
            }
            if (startingCheck && !interrupted) {
                return i;
            }
            interrupted = false;
            startingCheck = false;
        }
        return -1;
    }
};
