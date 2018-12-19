class Solution {
public:
    vector<vector<int>> permuteHelper(vector<int>& nums, int index) {
        if (index == 0) { // base case
            return {{nums[index]}};
        } else {
            auto prev = permuteHelper(nums, index-1);
            vector<vector<int>> result;
            int numElem = prev.size(); // number of elements in prev
            for (int i = 0; i < numElem; ++i) {
                for (int j = 0; j < index+1; ++j) { // all elements in prev has size same as index, 
                                                    // so to insert nums[index] to all places in each element of prev, need index + 1 inserts
                    auto copyElem = prev[i];
                    copyElem.insert(copyElem.begin()+j, nums[index]);
                    result.push_back(copyElem);
                }
            }
            return result;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int numsSize = nums.size();
        if (numsSize == 0) {
            return result;
        } else {
            return permuteHelper(nums, numsSize - 1);
        }
    }
};
