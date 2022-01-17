/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 */

/* Approach
   Note - Cannot do sliding window approach, since negative numbers are involved
   Hint - Similar approach to "Two Sum" problem, here we map sum up until current point in the array instead of just the array element itself and look for (current sum - target) instead of (target - current element)
   Explanation - https://www.youtube.com/watch?v=fFVZt-6sgyo
   Data structure:
   Use hash map PrefixSum to store mapping of the sum of a subarray to the number of subarrays which sum to that value
   Algorithm:
   Iterate through array, compute current sum up until that point
   Check hash map if there exists a subarray which when added to target = current sum i.e check for subarray which sums to (sum - target)
      Add the number of such subarrays to a count variable since each of these forms the start point of a continuous subarray which sums to target
   Increment hash map with current sum as key - PrefixSum[current sum]++;
   
   Complexity
   Time - Single traversal, O(n)
   Space - Hash map, O(n) */
   
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSum;
        map<int, int>::iterator it;
        int i;
        int sum = 0;
        int count = 0;
        
        prefixSum[0] = 1; //There is always a prefix (i.e subset) that sums to 0
        
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            it = prefixSum.find(sum - k);
            if (it != prefixSum.end()) {
                count += it->second;  //Removing this prefix sum from the sum so far results in target, so each such prefix adds to count
            }
            prefixSum[sum]++;  //Update the number of subsets that sum to current sum
        }
        
        return count;
    }
};
