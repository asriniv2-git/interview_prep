/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index. */

// Explanation - https://www.youtube.com/watch?v=Yan0cv2cLy8

// DP solution - (O(n^2))

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        int i, j;
        
        for (i = nums.size()-1; i >= 0; i--) {
            for (j = nums[i]; j >= 0; j--) {
                if ((i+j >= nums.size()-1) || (dp[i+j] == true)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};

// Non-DP "greedy" solution - O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target, i;
        
        target = nums.size()-1;
        
        for (i = nums.size()-1; i >= 0; i--) {
            if ((i+nums[i]) >= target) {
                target = i;
            }
        }
        
        if (target == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
