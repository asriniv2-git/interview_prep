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

/* Approach 1 - Heap
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

/* Approach 2 (Follow up) - Partial quicksort
   1. Create a hash map with key = element, value = number of occurences
   2. Create an array of the unique keys
   3. If array is sorted, all elements from index (n-k) will give the top k occuring elements
   4. Instead of sorting full array, intercept quicksort algorithm until pivot = n-k - since all elements to the right of pivot are greater
      - After each pivot selection, sort only the section of the array which contains index (n-k)
      - If n-k < pivot, sort left side; if greater sort right side
      - if n-k = pivot, return pivot
   5. Return keys array starting from index (n-k)
   
   Complexity
   O(N) - since only one half of the array is sorted each time (O(NlogN) if both sides need to be sorted ie full quicksort)
*/

class Solution {
private:
    map<int, int> hash;
    vector<int> keys;
public:
    int partition(int left, int right, int pivot) {
        int i, last_index, val_to_compare;
        
        val_to_compare = hash[keys[pivot]];
        
        // Swap pivot element with right most element to facilitate easy comparison
        swap(keys[pivot], keys[right]);
        
        // Do a series of swaps with the last element which is not less than pivot until all the smaller elements cluster at the beginning
        last_index = left;
        for (i = left; i <= right; i++) {
            if (hash[keys[i]] < val_to_compare) {
                swap(keys[i], keys[last_index]);
                last_index++;
            }
        }
        
        // Array is now partitioned such that all elements to the left of last_index are smaller than pivot, now swap pivot (right index) with last_index and return it
        swap(keys[last_index], keys[right]);
        return last_index;    
    }
    
    void quicksort(int left, int right, int index) {
        int pivot;
        
        pivot = left + (rand()%(right-left+1)); // Random pivot index selection
        
        pivot = partition(left, right, pivot);
        
        if (index == pivot) {
            return; 
        }
        if (index < pivot) {
            quicksort(left, pivot-1, index);
        }
        else {
            quicksort(pivot+1, right, index);
        }
        
        return;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>::iterator it;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        
        for (it = hash.begin(); it != hash.end(); it++) {
            keys.push_back(it->first);
        }
        
        quicksort(0, keys.size()-1, keys.size()-k);
        
        for (int i = keys.size()-k; i < keys.size(); i++) {
            res.push_back(keys[i]);
        }
        
        return res;
    }
};
