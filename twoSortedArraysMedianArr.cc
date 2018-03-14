class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0; // index for nums1
        int index2 = 0; // index for nums2
        int index = 0; // index for merged
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int totalSize = nums1Size + nums2Size;
        double result = 0;
        bool totalSizeEven = false;
        if (totalSize % 2 == 0) {
            totalSizeEven = true;
        }
        int middle = totalSize / 2;
        int merged[middle+1]; // the merged array size will never go over middle index number + 1
        for (int i = 0; i < middle+1; ++i) {
            if (index1 >= nums1Size) {
                merged[index] = nums2.at(index2);
                ++index2;
            } else if (index2 >= nums2Size) {
                merged[index] = nums1.at(index1);
                ++index1;
            } else if (nums1.at(index1) <= nums2.at(index2)) {
                merged[index] = nums1.at(index1);
                ++index1;
            } else if (nums1.at(index1) > nums2.at(index2)) {
                merged[index] = nums2.at(index2);
                ++index2;
            }
            ++index;
        }
        result = merged[middle];
        if (totalSizeEven) {
            result = (result + merged[middle-1]) / 2;
        }
        return result;
    }
};
