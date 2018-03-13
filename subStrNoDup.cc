class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int longest = 1;
        int currentMax = 1;
        int strLen = s.size();
        if (strLen == 0) {
            return 0;
        }
        for (int i = 0; i < strLen; i++) {
            index = i + 1;
            if (index == strLen) {
                break;
            }
            for (int j = i; j < index; j++) {
                if (s[j] == s[index]) {
                    break;
                } else if (j == index - 1) {
                    ++currentMax;
                    ++index;
                    j = i - 1;
                    if (index == strLen) {
                        break;
                    }
                }
            }
            if (longest < currentMax) {
                longest = currentMax;
            }
            currentMax = 1;
        }
        return longest;
    }
};
