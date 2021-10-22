/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i, j;
        vector<int> prev;
        vector<int> curr;
        
        prev.push_back(1);
        
        for (i = 1; i <= rowIndex; i++) {
            curr.push_back(1);
            for (j = 0; j < prev.size()-1; j++) {
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            prev = curr;
            curr.clear();
        }
        
        return prev;
    }
};
