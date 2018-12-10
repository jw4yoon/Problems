class Solution {
public:
        void minPathSumWithCache(vector<vector<int>>& grid, vector<vector<int>>& minSumHash, int row, int col, int prevSum, const int& gridRows, const int& gridCols) {
        int& currentSum = minSumHash[row][col];
        int otherSum = prevSum + grid[row][col];
        if (currentSum == 0) {
            currentSum = otherSum;
        } else {
            if (currentSum > otherSum) {
                currentSum = otherSum;
            }
        }
        if (row+1 == gridRows && col+1 == gridCols) {
            return;
        } else {
            int sumOfNextGrid;
            if (row + 1 < gridRows) {
                sumOfNextGrid = minSumHash[row+1][col];
                if (sumOfNextGrid == 0 || sumOfNextGrid > currentSum) { // so if the next grid's sum is smaller than current, don't try
                    minPathSumWithCache(grid, minSumHash, row+1, col, currentSum, gridRows, gridCols);
                }
            }
            if (col + 1 < gridCols) {
                sumOfNextGrid = minSumHash[row][col+1];
                if (sumOfNextGrid == 0 || sumOfNextGrid > currentSum) { // so if the next grid's sum is smaller than current, don't try
                    minPathSumWithCache(grid, minSumHash, row, col+1, currentSum, gridRows, gridCols);
                }
            }
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int gridRows = grid.size();
        int gridCols = grid[0].size();
        
        vector<vector<int>> minSumHash(gridRows, vector<int>(gridCols, 0)); // initialize with 0

        minPathSumWithCache(grid, minSumHash, 0, 0, 0, gridRows, gridCols);
        return minSumHash[gridRows-1][gridCols-1];
    }
};
