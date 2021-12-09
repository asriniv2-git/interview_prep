/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1 */

// Solution 1 (O(n^2)) - Top Down DP - Start with the last element and determine LIS for each backwards using previously determined solution (https://www.youtube.com/watch?v=cjWnW0hdF1Y)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j;
        int lis = 1;
        vector<int> dp(nums.size(), 1);
        
        for (i = nums.size()-1; i >= 0; i--) {
            for (j = i+1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i],1+dp[j]);   
                }
            }
            lis = max(lis, dp[i]);
        }
        
        return lis;
    }
};

// Solution 2 (O(nlogn)) - Binary search - Maintain temp LIS array, iterate through main array and replace smallest number in LIS array which is >= ith element, if all lesser then append (https://www.youtube.com/watch?v=i4NBDE8ZEV8)

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int l, r, mid;
        int index = -1;
        
        l = 0;
        r = nums.size()-1;
        
        while (l <= r) {
            mid = (l+r)/2;
            if (target <= nums[mid]) {
                index = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return index;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int i;
        vector<int> lis;
        int index = 0;
        
        lis.push_back(nums[0]);
        
        for (i = 1; i < nums.size(); i++) {
            index = binarySearch(lis, nums[i]);
            if (index == -1) {
                lis.push_back(nums[i]);
            }
            else {
                lis[index] = nums[i];
            }
        }
        
        return lis.size();
    }
};

