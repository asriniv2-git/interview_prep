/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major;
        int i;
        
        major = nums[0];
        
        for (i = 0; i < nums.size(); i++) {
            if (count == 0) {
                major = nums[i];
            }
            if (major == nums[i]) {
                count++;
            }
            else {
                count--;
            }
        }
        
        return major;
    }
};