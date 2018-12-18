class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int currentNum;
        int prevNum = nums[0];
        int numsSize = nums.size();
        int newArrayLen = 1;
        int occurenceCount = 1;
        int indToInsert = 1;
        for (int i = 1; i < numsSize; ++i) {
            currentNum = nums[i];                
            if (currentNum == prevNum) {
                ++occurenceCount;
            } else {
                occurenceCount = 1;
                prevNum = currentNum;
            }
            
            if (occurenceCount < 3) { // if occurred less than 3
                ++newArrayLen;
                nums[indToInsert] = currentNum;
                ++indToInsert;
            }
        }
        nums.erase(nums.begin()+indToInsert, nums.end()); // erase the back of the array
        return newArrayLen;
    }
};
