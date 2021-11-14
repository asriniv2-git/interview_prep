/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0] */

// O(n) space solution, two pointers used to track left and right products of each element in 2 arrays
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, j;
        vector<int> res(nums.size(), 1);
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        
        for (i = 1, j = nums.size()-2; i < nums.size(); i++, j--) {
            left[i] = left[i-1]*nums[i-1];
            right[j] = right[j+1]*nums[j+1]; 
        }
        
        for (i = 0; i < nums.size(); i++) {
            res[i] = left[i]*right[i];
        }
        
        return res;
    }
};

// O(1) space solution, convert the arrays into a single value
// Each element between the extremeties will be visited twice, once by left (compute left product) and once by right (compute right product) 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, j;
        vector<int> res(nums.size(), 1);
        int left = 1;
        int right = 1;
        
        for (i = 1, j = nums.size()-2; i < nums.size(); i++, j--) {
            left = left*nums[i-1];
            right = right*nums[j+1];
            res[i] *= left;
            res[j] *= right;
        }
      
        return res;
    }
};
