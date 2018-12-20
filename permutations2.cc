class Solution {
public:
    // map eliminates all duplicates
    map<vector<int>, int> permuteHelper(vector<int>& nums, int index) {
        if (index == 0) { // base case
            map<vector<int>, int> toReturn;
            toReturn[{nums[index]}] = 1;
            return toReturn;
        } else {
            auto prev = permuteHelper(nums, index-1);
            map<vector<int>, int> result;
            for (const auto& elem : prev) {
                for (int i = 0; i < index+1; ++i) {
                    auto copyElemFirst = elem.first;
                    copyElemFirst.insert(copyElemFirst.begin()+i, nums[index]);
                    result[copyElemFirst] = 1;
                }
            }
            return result;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>, int> resultFromHelper;
        vector<vector<int>> result;
        int numsSize = nums.size();
        if (numsSize == 0) {
            return result;
        } else {
            resultFromHelper = permuteHelper(nums, numsSize - 1);
            for (const auto& elem : resultFromHelper) { // copy all elements from map to result vector
                result.push_back(elem.first);
            }
            return result;
        }
    }
};
