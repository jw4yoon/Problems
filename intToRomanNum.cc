class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
        string newString = "";
        string current = "";
        int count = 10;
        while(num != 0) {
            int digit = num % count / (count / 10);
            if (digit == 0) {
                newString = current + newString;
                count *= 10;
                current = "";
            }
            if (digit >= 1 && digit <= 4 || digit == 9) {
                current += roman[count/10];
                if(digit == 4) {
                    num += (count / 10);   
                } else if (digit >= 1 && digit <= 3){
                    num -= (count / 10);
                }
            } else if (digit >= 5 && digit <= 8) {
                current += roman[count/2];
                num -= count/2;
            } 
            if (digit == 9) {
                current += roman[count];
                num -= (digit * (count / 10));
            }
        }
        newString = current + newString;
        return newString;
    }
};
