class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = abs(target - (nums[0] + nums[1] + nums[2])); // difference between the target and 3 numbers
        int sum = nums[0] + nums[1] + nums[2];
        int index1 = 0;
        int index2 = 1;
        int index3 = 2;
        int numsSize = nums.size();
        while(true) {
            int diffNow = abs(target - (nums[index1] + nums[index2] + nums[index3]));
            int sumNow = nums[index1] + nums[index2] + nums[index3];
            if (diffNow < diff) {
                diff = diffNow;
                sum = sumNow;
                if (diff == 0) {
                    return sum;
                }
            }
            if (index1 == numsSize - 3) {
                break;
            }
            if (index2 == numsSize - 2) {
                ++index1;
                index2 = index1 + 1;
                index3 = index2 + 1;
                continue;
            }
            if (index3 == numsSize - 1) {
                ++index2;
                index3 = index2 + 1;
                continue;
            }
            index3++;
        }
        return sum;
    }
};
