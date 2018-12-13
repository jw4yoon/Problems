class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty()) {
            return;
        }
        int nums1Ind = 0;
        int nums2Ind = 0;
        int nums1ElemLeft = m;
        int nums2ElemLeft = n;
        int count = 0;
        while(nums1Ind < m + n) {
            int* num1 = &nums1[nums1Ind];
            int* num2 = &nums2[nums2Ind];
            if (nums1ElemLeft == 0) { // only elements in num2 are left
                *num1 = *num2;
                ++nums1Ind;
                ++nums2Ind;
                --nums2ElemLeft;
            } else if (nums2ElemLeft == 0 || *num1 <= *num2) {
                ++nums1Ind;
                --nums1ElemLeft;
            } else { // *num1 > * num2
                int temp = *num1;
                *num1 = *num2;
                --nums2ElemLeft;
                for (int i = 1; i <= nums1ElemLeft && i < m + n; ++i) { // right shift elements by 1
                    int temp2 = *(num1+i);
                    *(num1+i) = temp;
                    temp = temp2;
                }
                ++nums1Ind;
                ++nums2Ind;
            }
        }
    }
};
