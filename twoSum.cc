class twoSum {
    map<int, int> dict;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            dict[nums[i]] = i;
        }
        int pair;
        for (int i = 0; i < numsSize; ++i) {
            pair = target - nums[i];
            if (dict.find(pair) != dict.end() && dict[pair] != i) {
                vector<int> result;
                result.push_back(i);
                result.push_back(dict[pair]);
                return result;
            }
        }
    }
};

