/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, mid;
        int res;
        
        left = 0;
        right = nums.size()-1;

        // Last element greater than first, means not rotated or rotated n times
        if ((nums.size() == 1) || (nums[nums.size()-1] > nums[0])) {
            return binarySearch(nums, left, right, target);
        }

        mid = findMinIndex(nums, left, right);
        
        if (target <= nums[right]) {
            return binarySearch(nums, mid, right, target);
        }
        if (target >= nums[left]) {
            return binarySearch(nums, left, mid-1, target);
        }
        
        return -1;
    }

    int findMinIndex(vector<int>& nums, int left, int right) {
        int mid;

        mid = (left+right)/2;

        if (nums[mid] > nums[mid+1]) {
            return mid+1;
        }

        if (nums[mid] < nums[mid-1]) {
            return mid;
        }

        if (nums[mid] < nums[left]) {
            return findMinIndex(nums, left, mid-1);
        }
        else {
            return findMinIndex(nums, mid+1, right);
        }
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int mid;
        
        if (left > right) {
            return -1;
        }
        
        mid = (left+right)/2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if (target > nums[mid]) {
            return binarySearch(nums, mid+1, right, target);
        }
        else {
            return binarySearch(nums, left, mid-1, target);
        }
    }
};
