/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = 0;
        int i;
        
        for (i = 0; i < nums.size(); i++) {
            cur_sum = cur_sum + nums[i];
            if (cur_sum < 0) {
                cur_sum = 0;
            }
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
            }
        }
        
        return max_sum;
        
    }
};
