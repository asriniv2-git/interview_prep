/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/

class Solution {
public:
    string longestPalindrome(string s) {
        int i;
        int len1, len2;
        int maxLen = 1;
        int start = 0;
        int end = 0;
        
        for (i = 0; i < s.size(); i++) {
            len1 = expandAroundCenter(s, i, i);
            len2 = expandAroundCenter(s, i, i+1);
            
            if (len1 > maxLen) {
                start = i - (len1/2);
                end = i + (len1/2);
                maxLen = len1;
            }
            
            if (len2 > maxLen) {
                start = i - (len2/2) + 1;
                end = i + (len2/2);
                maxLen = len2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
    int expandAroundCenter(string s, int left, int right) {
        int i, j;
        
        for (i = left, j = right; i >= 0 && j < s.size(); i--, j++) {
            if (s[i] != s[j]) {
                break;
            }
        }
        
        return j - i - 1;
    }
};
