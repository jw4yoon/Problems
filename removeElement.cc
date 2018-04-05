class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] == val) {
                nums.erase(nums.begin()+i);
                --numsSize;
                --i;
            }
        }
        return numsSize;
    }
};
