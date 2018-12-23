class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "") {
            return true;
        }
        bool isPossible = false;
        int elemSize = 0;
        for (const auto& elem : wordDict) {
            elemSize = elem.size();
            if (elem == s.substr(0, elemSize)) {
                isPossible = wordBreak(s.substr(elemSize), wordDict);
                if (isPossible) {
                    return true;
                }
            }
        }
        return false;
    }
};
