class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // vector<int> that is going to be returned
        if (matrix.empty()) { // if matrix is empty, return an empty vector of int
            return result;
        }
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();
        int limit = 0; // the limit of when should we go until. Gets incremented when we reach at certain point
        const int numElements = numRows * numCols; // number of elements in matrix
        int countElements = 0; // element counter
        int currentRow = 0; // current position of row
        int currentCol = 0; // current position of column
        bool goRight = true; // boolean variables to indicate which way we are goin
        bool goDown = false;
        bool goLeft = false;
        bool goUp = false;
        const int leftAndUpperBound = -1; // number that indicates left and upper bound
        while (countElements < numElements) { // go out of loop when we finish printing all elements
            result.push_back(matrix[currentRow][currentCol]);
            ++countElements;
            if (goRight) {
                ++currentCol;
                if (currentCol == numCols - limit) {
                    --currentCol;
                    goRight = false;
                    goDown = true;
                    ++currentRow;
                }
            } else if (goDown) {
                ++currentRow;
                if (currentRow == numRows - limit) {
                    --currentRow;
                    goDown = false;
                    goLeft = true;
                    --currentCol;
                }
            } else if (goLeft) {
                --currentCol;
                if(currentCol == leftAndUpperBound + limit) {
                    ++currentCol;
                    ++limit; // increase the limit variable here
                    goLeft = false;
                    goUp = true;
                    --currentRow;
                }
            } else if (goUp) {
                --currentRow;
                if (currentRow == leftAndUpperBound + limit) {
                    ++currentRow;
                    goUp = false;
                    goRight = true;
                    ++currentCol;
                }
            }
        }
        return result;
    }
};
