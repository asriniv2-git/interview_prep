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
        vector<vector<int>> pasTri(rowIndex+1);
        
        pasTri[0].push_back(1);
        
        for (i = 1; i <= rowIndex; i++) {
            pasTri[i].push_back(1);
            for (j = 0; j < pasTri[i-1].size()-1; j++) {
                pasTri[i].push_back(pasTri[i-1][j] + pasTri[i-1][j+1]);
            }
            pasTri[i].push_back(1);
        }
        
        return pasTri[rowIndex];
    }
};
