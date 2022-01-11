/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size. */

/* Approach 1 (Heap)
   1. Create a hash map with key = element, value = number of occurences
   2. Push (value,key) pairs onto min heap of size k, such that smallest value is evicted when size > k
   3. Go through the heap and pop the pair/push the key into result vector
   
   Complexity
   O(Nlogk) - N to traverse the hash map, logk for each insertion into the heap
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hash;
        map<int, int>::iterator it;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        int i;
        vector<int> res;
        
        for (i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        
        for (it = hash.begin(); it != hash.end(); it++) {
            heap.push(make_pair(it->second, it->first));
            if (heap.size() > k) {
                heap.pop();
            }
        }
        hash.clear();
        
        for (i = 0; i < k; i++) {
            res.push_back((heap.top()).second);
            heap.pop();
        }
        
        return res;
    }
};
