class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1Ind = m - 1; // start from the end
        int nums2Ind = n - 1;
        int indToInsert = nums1.size() - 1;
        while(nums2Ind > -1) {
            if (nums1Ind > -1 && nums1[nums1Ind] >= nums2[nums2Ind]) {
                nums1[indToInsert] = nums1[nums1Ind];
                --nums1Ind;
                --indToInsert;
            } else {
                nums1[indToInsert] = nums2[nums2Ind];
                --nums2Ind;
                --indToInsert;
            }
        }
    }
};
