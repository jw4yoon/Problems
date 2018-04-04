class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsSize = nums.size();
        int index = 0;
        for (int i = 1; i < numsSize; ++i) {
            if (nums[index] == nums[i]) {
                nums.erase(nums.begin()+i);
                --i;
                --numsSize;
            } else {
                ++index;
            }
        }
        return numsSize;
    }
};
