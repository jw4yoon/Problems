double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int index = 0; // for nums1
    int index2 = 0; // for nums2
    int sum = nums1Size + nums2Size;
    int middle = sum / 2;
    double result = 0;
    int* newA = malloc(sizeof(int) * sum);
    
    // insert to new array in sorted order
    for (int i = 0; i < sum; i++) {
        if (index >= nums1Size) {
            newA[i] = nums2[index2];
            ++index2;
        } else if (index2 >= nums2Size) {
            newA[i] = nums1[index];
            ++index;
        } else if (nums1[index] <= nums2[index2]) {
            newA[i] = nums1[index];
            ++index;
        } else if (nums1[index] > nums2[index2]) {
            newA[i] = nums2[index2];
            ++index2;
        }
    }
    
    if (sum % 2 == 0) {
        result = (double) (newA[middle - 1] + newA[middle]) / 2;
    } else {
        result = (double) newA[middle];
    }
    free(newA);
    return result;
}
