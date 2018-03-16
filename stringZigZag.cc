class Solution {
public:
    string convert(string s, int numRows) {
        string newString = ""; // string to be returned
        string part = s; // part of string that is being added to newString
        int length = s.length(); // string length
        bool inverse = false; // flag to decide how much step to jump over (ex. 2->2->2->... or 4->2->4->2->...)
        int initialStep = 0;
        int inverseStep = 0;
        int lastInitStep = 0;
        int lastInvStep = 0;
        int index = 0; // index moving in string s to store character at that index to part
        int count = 0;
        bool wentThrough = false;
        if (numRows == 1) {
            return s;
        }
        for (int i = 0; i < numRows; ++i) {
            if (i >= length) {
                break;
            }
            initialStep = (numRows - i - 1) * 2; // initial step(jump) that I need to take to get next character
            inverseStep = i * 2;
            if (i == 0) {
                inverseStep = initialStep;
                lastInitStep = initialStep;
                lastInvStep = initialStep;
            }
            if (i == numRows -1) {
                initialStep = lastInitStep;
                inverseStep = lastInvStep;
            }
            index = i;
            while(index < length) {
                part[count] = s[index];
                ++count;
                wentThrough = true;
                if (length == 1) {
                    break;
                } else if (!inverse) {
                    index += initialStep;
                } else {
                    index += inverseStep;
                }
                inverse = !inverse;
                if (wentThrough && index < numRows) {
                    break;
                }
            }
            string replace = part.substr(0, count);
            newString = newString + replace;
            count = 0;
            wentThrough = false;
            inverse = false;
        }
        return newString;
    }
};
