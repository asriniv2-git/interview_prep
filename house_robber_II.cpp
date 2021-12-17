/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1, rob2;
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        rob1 = helperRob(nums, 0, nums.size()-2);
        rob2 = helperRob(nums, 1, nums.size()-1);
        
        return max(rob1, rob2);
    }
    
    int helperRob(vector<int>& nums, int start, int end) {
        int rob1, rob2, temp;
        int i;
        
        rob1 = 0;
        rob2 = 0;
        
        for (i = start; i <= end; i++) {
            temp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};
