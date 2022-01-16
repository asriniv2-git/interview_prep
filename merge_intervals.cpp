/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104 */

/* Approach
1. Sort the intervals based on first value
2. Push first interval into result vector
3. Iterate through the intervals, check for overlap between last interval and current
   - If current[0] <= last[1], last[1] = max(last[1], current[1])
   - Else, push current interval into result
   
   Complexity
   O(NlogN) - Sort is O(NlogN) and then linear traversal is O(N), O(NlogN) + O(N) = O(NlogN) */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i;
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        res.push_back(intervals[0]);
        
        for (i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {  //Check if overlap
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            } 
            else { //No overlap, start new interval
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
