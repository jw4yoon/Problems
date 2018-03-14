class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0; // index for nums1
        int index2 = 0; // index for nums2
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int totalSize = nums1Size + nums2Size;
        double result = 0;
        bool totalSizeEven = false;
        if (totalSize % 2 == 0) {
            totalSizeEven = true;
        }
        int middle = totalSize / 2;
        vector<int> merged;
        for (int i = 0; i < middle+1; ++i) {
            if (index1 >= nums1Size) {
                merged.push_back(nums2.at(index2));
                ++index2;
            } else if (index2 >= nums2Size) {
                merged.push_back(nums1.at(index1));
                ++index1;
            } else if (nums1.at(index1) <= nums2.at(index2)) {
                merged.push_back(nums1.at(index1));
                ++index1;
            } else if (nums1.at(index1) > nums2.at(index2)) {
                merged.push_back(nums2.at(index2));
                ++index2;
            }
        }
        result = merged.back(); // == merged.at(middle)
        if (totalSizeEven) {
            result = (result + merged.at(middle-1)) / 2;
        }
        return result;
    }
};

