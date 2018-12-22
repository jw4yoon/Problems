class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const auto& elem : nums) {
            result^=elem; // xor
        }
        return result;
    }
};
