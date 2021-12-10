/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.*/

// Solution - 2 dimensional DP, refer https://www.youtube.com/watch?v=Ua0GhsJSlWM

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        int i, j;
        
        for (i = text1.size()-1; i >= 0; i--) {
            for (j = text2.size()-1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};
