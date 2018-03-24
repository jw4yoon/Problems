class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string shortest = strs.at(0);
        int vSize = strs.size();
        for (int i = 0; i < vSize; ++i) {
            if (strs.at(i).length() < shortest.length()) {
                shortest = strs.at(i);
            }
        }
        int strLen = shortest.length();
        int vIndex = 0;
        //cout << vSize << endl;
        while(vIndex < vSize){
            if (shortest.compare(0, strLen, strs.at(vIndex), 0, strLen) != 0) { // compare shortest[0-strLen] with strs[vIndex][0-strLen] and if they are different do this
                vIndex = 0;
                strLen -= 1;
                shortest = shortest.substr(0, strLen);
            } else {
                ++vIndex;
                //cout << "++vIndex called" << vIndex << " "<< endl;
            }
            if (shortest == "") {
                return "";
            }
        }
        return shortest;
    }
};
