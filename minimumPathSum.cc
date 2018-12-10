class Solution {
public:
    void minPathSumWithCache(vector<vector<int>>& grid, map<vector<int>, int>& minSumDict, int row, int col, int prevSum, const int& gridRows, const int& gridCols) {
        vector<int> currentPos{row, col};
        int& currentSum = minSumDict[currentPos];
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
            if (row + 1 < gridRows) {
                minPathSumWithCache(grid, minSumDict, row+1, col, currentSum, gridRows, gridCols);
            }
            if (col + 1 < gridCols) {
                minPathSumWithCache(grid, minSumDict, row, col+1, currentSum, gridRows, gridCols);
            }
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        map<vector<int>, int> minSumDict;
        int gridRows = grid.size();
        int gridCols = grid[0].size();
        minPathSumWithCache(grid, minSumDict, 0, 0, 0, gridRows, gridCols);
        return minSumDict[{gridRows-1,gridCols-1}];
    }
};
