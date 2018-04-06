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
            if (haystack[i] == needle[0]) {
                if (i + needleLen <= haystackLen && haystack.substr(i, needleLen) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};
