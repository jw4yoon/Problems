class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        int largest = nums[0];
        int numsSize = nums.size();
        for (int i = 1; i < numsSize; ++i) { // get the largest number in the vector
            if (largest < nums[i]) {
                largest = nums[i];
            }
        }
        if (largest <= 0) {
            return 1;
        } else {
            int numsInd = 0;
            const int size = largest + 1; // extra space for 0
            int sortedPositiveNums[size] = {0}; // initialize every element to zero
            for (int i = 0; i < numsSize; ++i) { // put in positive numbers 
                if (nums[numsInd] >= 0) {
                    sortedPositiveNums[nums[numsInd]] = nums[numsInd];
                }
                ++numsInd;
            }
            for (int i = 1; i < largest+1; ++i) { // find out missing number
                if (sortedPositiveNums[i] == 0) {
                    return i;
                }
            }
        }
        return largest+1;
    }
};
