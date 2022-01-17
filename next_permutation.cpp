/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100 */

/* Approach
   Iterate backwards from penultimate element of array, find first decreasing element nums[i] < nums[i+1]
   Set j = i+1, loop through till nums[j] <= nums[i] - to find the smallest number greater than nums[i]
   Swap nums[i] and nums[j-1], now nums[i] is in the correct position
   Reverse subarray starting from nums[i+1] to ensure it is in increasing order
   
   Complexity
   Time - 2 linear traversals plus reverse = O(n+n+n) = O(n) 
   Space - O(1) */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        
        for (i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                for (j = i+1; j < nums.size(); j++) {
                    if (nums[j] <= nums[i]) {
                        break;
                    }
                }
                swap(nums[i], nums[j-1]);
                break;
            }
        }
        
        reverse(nums.begin()+i+1, nums.end());
    }
};
