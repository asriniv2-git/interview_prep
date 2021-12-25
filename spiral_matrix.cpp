/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int index, lastRow, lastCol, firstRow, firstCol, count, size;
        
        firstRow = 0;
        firstCol = 0;
        lastRow = matrix.size()-1;
        lastCol = matrix[0].size()-1;
        count = 0;
        size = (lastRow+1)*(lastCol+1);
        while (count < size) { // Keep iterating until all elements are processed
            // Row fixed, column moves right
            for (index = firstCol; index <= lastCol && count < size; index++) {
                res.push_back(matrix[firstRow][index]);
                count++;
            }
            // Column fixed, row moves down
            for (index = firstRow+1; index <= lastRow && count < size; index++) {
                res.push_back(matrix[index][lastCol]);
                count++;
            }
            // Row fixed, column moves left
            for (index = lastCol-1; index >= firstCol && count < size; index--) {
                res.push_back(matrix[lastRow][index]);
                count++;
            }
            // Column fixed, row moves up
            for (index = lastRow-1; index >= (firstRow+1) && count < size; index--) {
                res.push_back(matrix[index][firstCol]);
                count++;
            }
            // Move inwards, update row and column accordingly
            lastRow--;
            lastCol--;
            firstRow++;
            firstCol++;
        }
        
        return res;
    }
};
