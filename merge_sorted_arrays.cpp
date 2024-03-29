/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> nums3;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            }
            else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        
        while (i < m) {
            nums3.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            nums3.push_back(nums2[j]);
            j++;
        }
        
        for (i = 0; i < m+n; i++) {
            nums1[i] = nums3[i];
        }
    }
};
