class Solution {
public:
    string addBinary(string a, string b) {
        int aInd = a.length() - 1; // start from the back
        int bInd = b.length() - 1;
        int carryFromPrevious = 0;
        string result = "";
        while(aInd >= 0 || bInd >= 0) {
            int currentSum = carryFromPrevious;
            if (aInd >= 0) {
                currentSum += (a[aInd] - '0'); // convert char to int and add
            }
            if (bInd >= 0) {
                currentSum += (b[bInd] - '0');
            }
            if (currentSum % 2 == 0) { // adds up to 0 or 2
                result = "0" + result;
                carryFromPrevious = currentSum == 0 ? 0 : 1;
            } else { // adds up to 1 or 3
                result = "1" + result;
                carryFromPrevious = currentSum == 1 ? 0 : 1;
            }
            --aInd;
            --bInd;
        }
        if (carryFromPrevious != 0) { // left over
            result = "1" + result;
        }
        return result;
    }
};
