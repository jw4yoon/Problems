class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (roman[s[i]] < roman[s[i+1]]) {
                num -= roman[s[i]];
            } else {
                num += roman[s[i]];
            }
        }
        return num;
    }
};
