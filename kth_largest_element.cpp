/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104 */

// Solution - Quick select algorithm already covered in kth most frequent occurence.

class Solution {
public:
    int partition(vector<int>& nums, int left, int right, int pivot) {
        int i, last_index;
        
        swap(nums[pivot], nums[right]);
        
        last_index = left;
        for (i = left; i <= right; i++) {
            if (nums[i] < nums[right]) {
                swap(nums[i], nums[last_index]);
                last_index++;
            }
        }
        swap(nums[last_index], nums[right]);
        
        return last_index;
        
    }
    
    int quickselect(vector<int>& nums, int left, int right, int k) {
        int pivot;
        
        pivot = left + (rand()%(right-left+1));
        
        pivot = partition(nums, left, right, pivot);
        
        if (pivot == (nums.size()-k)) {
            return nums[pivot];
        }
        else if (pivot < (nums.size()-k)) {
            return quickselect(nums, pivot+1, right, k);
        }
        else {
            return quickselect(nums, left, pivot-1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, k);
    }
};
