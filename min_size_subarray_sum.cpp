/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i;
        int j = 0;
        int sum = 0;
        int minLen = 0;
        
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while (sum >= target) {
                // Once target is found, keep reducing size to check for subarray within subarray since min length is required
                if (((i-j+1) < minLen) || !minLen) {
                    minLen = i-j+1;
                }
                sum -= nums[j];
                j++;
            }
        } 
        
        return minLen;
    }
};
