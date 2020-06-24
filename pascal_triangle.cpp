/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i, j;
        vector<vector<int>> pasTri(numRows);
        
        if (numRows) {
            pasTri[0].push_back(1);
        }
        
        for (i = 1; i < numRows; i++) {
            pasTri[i].push_back(1);
            for (j = 0; j < pasTri[i-1].size()-1; j++) {
                pasTri[i].push_back(pasTri[i-1][j] + pasTri[i-1][j+1]);
            }
            pasTri[i].push_back(1);
        }
        
        return pasTri;
    }
};
