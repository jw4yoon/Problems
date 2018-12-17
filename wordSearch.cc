class Solution {
public:
    bool existHelper(vector<vector<char>>& board, vector<vector<bool>> visitedMap, string word, int row, int col, int& numRows, int& numCols) {
        visitedMap[row][col] = true;
        if (word == "") {
            return true;
        } else if (board[row][col] == word[0]) {
            bool upResult = false;
            bool downResult = false;
            bool leftResult = false;
            bool rightResult = false;
            string newWord = word.substr(1);
            if (newWord == "") {
                return true;
            }
            if (row - 1 >= 0 && !visitedMap[row-1][col]) {
                upResult = existHelper(board, visitedMap, newWord, row-1, col, numRows, numCols);
            } 
            if (row + 1 < numRows && !visitedMap[row+1][col]) {
                downResult = existHelper(board, visitedMap, newWord, row+1, col, numRows, numCols);
            }
            if (col - 1 >= 0 && !visitedMap[row][col-1]) {
                leftResult = existHelper(board, visitedMap, newWord, row, col-1, numRows, numCols);
            }
            if (col + 1 < numCols && !visitedMap[row][col+1]) {
                rightResult = existHelper(board, visitedMap, newWord, row, col+1, numRows, numCols);
            }
            return upResult || downResult || leftResult || rightResult;
        } else {
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") {
            return true;
        }
        if (board.empty()) {
            return false;
        }
        int numRows = board.size();
        int numCols = board[0].size();
        vector<vector<bool>> visitedMap(numRows, vector<bool>(numCols, false)); // initialize with false
        bool result;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                result = existHelper(board, visitedMap, word, i, j, numRows, numCols);
                if (result == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
