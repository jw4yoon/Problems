class Solution {
    map<int, vector<string>> store; // key == n, vector<string> = combinations when n is equal to key. Stores previous combinations to avoid duplication of work
public:
    vector<vector<int>> generatePairs(int n) { // from numbers 1 to n-1, make vector of pairs that adds up to n.
        // ex. if n == 4, pairs are {1,3}, {2, 2}, {3, 1}
        vector<vector<int>> pairsVec;
        vector<int> pair;
        map<vector<int>, int> validPairs;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i + j == n) {
                    pair.push_back(i);
                    pair.push_back(j);
                    if (validPairs.find(pair) == validPairs.end()) {
                        pairsVec.push_back(pair);
                        validPairs[pair] = 1;
                        pair.pop_back();
                        pair.pop_back();
                    }
                }
            }
        }
        return pairsVec;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        map<string, int> checkDup;
        if (n == 1) {
            result.push_back("()");
        } else {
            vector<string> returned = generateParenthesis(n - 1);
            int returnedSize = returned.size();
            for (int i = 0; i < returnedSize; ++i) {
                result.push_back("(" + returned[i] + ")");
            }
            vector<vector<int>> validPairs = generatePairs(n); // get pairs that add up to n
            int validPairsSize = validPairs.size();
            for (int i = 0; i < validPairs.size(); ++i) {
                int num = validPairs[i].front(); // to get combinations of this number
                int num2 = validPairs[i].back(); // to get combinations of this number
                int jSize = store[num].size(); // number of combinations that this number has
                int kSize = store[num2].size(); // // number of combinations that this number has
                
                for (int j = 0; j < jSize; ++j) {
                    for (int k = 0; k < kSize; ++k) {
                        string s1 = store[num][j];
                        string s2 = store[num2][k];
                        if (checkDup.find(s1 + s2) == checkDup.end()) { // if this string is not duplicate, add to result
                            result.push_back(s1 + s2);
                            checkDup[s1 + s2] = 1;
                        }
                    }
                }
            }
        }
        store[n] = result; // store the current result for future usage
        return result;
    }
};
