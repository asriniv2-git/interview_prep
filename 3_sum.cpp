/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k;
        vector<vector<int>> triplets;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < nums.size(); i++) {
            // If a number repeats, skip it to avoid duplicate solution
            if ((i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            // Apply sorted 2 sum algorithm with target = 0 - nums[i]
            j = i+1;
            k = nums.size()-1;
            while (j < k) {
                if ((nums[j]+nums[k]) == (-nums[i])) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    // Keep incrementing/decrementing until next unique number found to avoid duplicate solution
                    do {
                        j++;
                    } while ((j < k) && (nums[j] == nums[j-1]));
                    do {
                        k--;
                    } while ((j < k) && (nums[k] == nums[k+1]));
                }
                else if ((nums[j]+nums[k]) < (-nums[i])) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        
        return triplets;
    }
};
