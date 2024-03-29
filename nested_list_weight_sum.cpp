/*Approach
  Recursive algorithm
  Iterate through nestedList
  If nestedList[i] is integer:
      sum += nestedList[i]*depth
  else:
      sum += call itself with nestedList[i], depth+1 as arguments
   return sum
      
  Complexity
  O(n) - Linear traversal through all the integers in the list */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        return helperDepthSum(nestedList, 0);
    }

    int helperDepthSum(const vector<NestedInteger>& nestedList, int depth) {
        int i;
        int sum = 0;

        for (i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                sum += nestedList[i].getInteger()*depth;
            }
            else {
                sum += helperDepthSum(nestedList[i].getList(),depth+1);
            }
        }

        return sum;
    }
};
