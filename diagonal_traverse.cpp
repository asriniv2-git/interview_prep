/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = 0;
        int col = 0;
        int newRow, newCol;
        int direction = 1;
        int numRows, numCols;
        vector<int> res;
        
        numRows = mat.size();
        numCols = mat[0].size();
        while (row < numRows && col < numCols) {
            res.push_back(mat[row][col]);
            newRow = (direction == 1) ? row-1 : row+1; //Upward direction - row decrements, downward - increments
            newCol = (direction == 1) ? col+1 : col-1; //Upward direction - col increments, downward - decrements
            if (newRow < 0 || newCol == numCols || newCol < 0 || newRow == numRows) { //End of one direction, set new row and column start (head) 
                if (direction == 1) { //End of upward direction
                    row = (newCol == numCols) ? newRow+2 : 0;
                    col = (newCol == numCols) ? numCols-1 : newCol;
                    direction = -1; //Reverse direction
                }
                else { //End of downward direction
                    row = (newRow == numRows) ? numRows-1 : newRow;
                    col = (newRow == numRows) ? newCol+2 : 0;
                    direction = 1; //Reverse direction
                }
            }
            else {
                row = newRow;
                col = newCol;
            }
        }
        
        return res;
    }
};

//Backup (simpler) solution - For some reason, time limit exceeds in spite of same complexity (O(mxn))

int startRow = 0;
int startCol = 0;
int i, j;
vector<int> res;

while (startRow < mat.size() && startCol < mat[0].size()) {
    // Upward direction
    for (i = startRow, j = startCol; i >= 0 && j < mat[0].size(); i--, j++) {
        res.push_back(mat[i][j]);
    }
    startRow = (i >= 0) ? i+2 : 0;
    startCol = (j < mat[0].size()) ? j : mat[0].size()-1;
    // Downward direction
    for (i = startRow, j = startCol; i < mat.size() && j >= 0; i++, j--) {
        res.push_back(mat[i][j]);
    }
    startRow = (i < mat.size()) ? i : mat.size()-1;
    startCol = (j >= 0) ? j+2 : 0;
}

return res;
