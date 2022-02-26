/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104 */

/*  Approach 1
    Iterate over array
    For each point, compute distance
    Push onto max heap
    if heap.size() > k, evict front ie largest element
    Final heap will be k smallest elements ie distances 
       
    Complexity
    Time - Linear traversal plus each push to heap of size k is logk - O(nlogk)
    Space - O(k) */

/*  Approach 2
    Quick select algorithm with sorting based on distance (refer k most frequent problem for code) 
       
    Complexity
    Time - Sample size reduced by half each time - n + n/2 + n/4 + n/8.... = O(2n) = O(n)
    Space - O(1) */


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int i, dist;
        priority_queue<pair<int,int>> heap;
        vector<vector<int>> res;
        
        for (i = 0; i < points.size(); i++) {
            dist = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            heap.push(make_pair(dist, i));
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        while (!heap.empty()) {
            res.push_back(points[heap.top().second]);
            heap.pop();
        }
        
        return res;
    }
};
