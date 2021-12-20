/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6 */

// Most optimal solution - DP with O(n) space complexity, Explanation - https://www.youtube.com/watch?v=IlEsdxuD4lY

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> currRow(n, 1);
        vector<int> prevRow(n, 1);
        int i, j;
        
        for (i = m-1; i >= 1; i--) {  // Last row (prevRow) is all 1s, only m-1 rows need to be computed
            for (j = n-2; j >= 0; j--) {
                currRow[j] = currRow[j+1]+prevRow[j];
            }
            prevRow = currRow;
        }
        
        return currRow[0];
    }
};

// Solution 2 (figured out by self) - DP with O(mxn) space complexity

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
        int i, j;
        
        for (i = 2; i < m+1; i++) {
            for (j = 2; j < n+1; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
};
