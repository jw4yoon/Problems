class Solution {
    map<char, int> dict; // key is a character and value is the character's index in string s
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int strLen = s.size();
        int longest = 0;
        int currentMax = 0;
        while(index < strLen) {
            if (dict.find(s[index]) != dict.end()) {
                index = dict[s[index]] + 1;
                dict.clear();
                currentMax = 0;
            } else {
                dict[s[index]] = index;
                ++index;
                ++currentMax;
                if (longest < currentMax) {
                    longest = currentMax;
                }
            }
        }
        return longest;
    }
};
