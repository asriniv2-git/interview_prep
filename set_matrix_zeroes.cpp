/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j;
        bool firstColZero = false;
        bool firstRowZero = false;
        
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[i].size(); j++) {
                // If an element is zero, we set the first element of the corresponding row and column to 0
                // Except for elements in the first row and first column so to as differentiate between
                // whether they were originally 0 or set to 0 for tracking
                // Use flags to save info about the former, to be zeroed out at the end
                if (i == 0 && matrix[i][j] == 0) {
                    firstRowZero = true;
                }
                if (j == 0 && matrix[i][j] == 0) {
                    firstColZero = true;
                }
                if (i != 0 && j != 0 && matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // Iterate over the array once again from (1,1) onwards, update the elements.
        for (i = 1; i < matrix.size(); i++) {
            for (j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // See if the first row needs to be set to zero as well
        if (firstRowZero) {
            for (j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        
        // See if the first column needs to be set to zero as well
        if (firstColZero) {
            for (i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
