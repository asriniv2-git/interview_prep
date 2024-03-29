/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/

/* O(logn) */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first, last;
        
        first = 0;
        last = nums.size()-1;
        
        return binarySearch(first, last, nums, target);
    }
    
    int binarySearch(int first, int last, vector<int>& nums, int target) {
        int mid;
        
        if (last < first) {
            return first;
        }
        
        mid = (first+last)/2;
        
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {
            return binarySearch(first, mid-1, nums, target);
        }
        else {
            return binarySearch(mid+1, last, nums, target);
        }
    }
};

/* O(n) */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        
        for (i = 0; i < nums.size(); i++) {
            if ((nums[i] >= target) || (i == nums.size() - 1)) {
                return i;
            }
        }
        
        return 0; 
    }
};
