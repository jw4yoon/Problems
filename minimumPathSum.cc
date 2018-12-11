class Solution {
public:
    void minPathSumWithCache(vector<vector<int>>& grid, vector<vector<int>>& minSumHash, int row, int col, const int& gridRows, const int& gridCols, int minSumOnCurrentGrid) {
        if (row+1 == gridRows && col+1 == gridCols) { // arrived at bottom right
            return;
        } else {
            int otherSumOfNextGrid;
            if (row + 1 < gridRows) {
                int& sumOfNextGrid = minSumHash[row+1][col];
                otherSumOfNextGrid = minSumOnCurrentGrid + grid[row+1][col];
                if (sumOfNextGrid == 0 || sumOfNextGrid > otherSumOfNextGrid) { // so if the next grid's sum is smaller than current, don't try
                    sumOfNextGrid = otherSumOfNextGrid;
                    minPathSumWithCache(grid, minSumHash, row+1, col, gridRows, gridCols, sumOfNextGrid);
                }
            }
            if (col + 1 <gridCols) {
                int& sumOfNextGrid = minSumHash[row][col+1];
                otherSumOfNextGrid = minSumOnCurrentGrid + grid[row][col+1];
                if (sumOfNextGrid == 0 || sumOfNextGrid > otherSumOfNextGrid) { // so if the next grid's sum is smaller than current, don't try
                    sumOfNextGrid = otherSumOfNextGrid;
                    minPathSumWithCache(grid, minSumHash, row, col+1, gridRows, gridCols, sumOfNextGrid);
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
        
        int minSumOnCurrentGrid = grid[0][0];
        minSumHash[0][0] = minSumOnCurrentGrid;

        minPathSumWithCache(grid, minSumHash, 0, 0, gridRows, gridCols, minSumOnCurrentGrid);
        return minSumHash[gridRows-1][gridCols-1];
    }
};
