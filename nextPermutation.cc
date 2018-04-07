class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsSize = nums.size();
        int index = 1;
        int lowNum;
        int lowNumI;
        while(true) { 
            if (index == numsSize) { // need to reverse
                for (int i = 0; i < numsSize / 2; ++i) {
                    int temp = nums[i];
                    nums[i] = nums[numsSize-1-i];
                    nums[numsSize-1-i] = temp;
                }
                break;
                
            }
            int swap = nums[numsSize-index];
            int swap2 = nums[numsSize-index-1];
            if (swap > swap2) {
                lowNum = swap;
                lowNumI = numsSize-index;
                for (int i = numsSize-index; i < numsSize; ++i) {
                    if (nums[i] > swap2 && nums[i] < swap && nums[i] < lowNum) {
                        lowNum = nums[i];
                        lowNumI = i;
                    }
                }
                int temp = swap2;
                nums[numsSize-index-1] = lowNum;
                nums[lowNumI] = temp;
                for (int i = numsSize-index; i < numsSize; ++i) {
                    for (int j = i + 1; j < numsSize; ++j) {
                        if (nums[j] < nums[i]) {
                            temp = nums[i];
                            nums[i] = nums[j];
                            nums[j] = temp;
                        }
                    }
                }
                break;
            } else if (swap <= swap2) {
                ++index;
            }
        }
    }
};
