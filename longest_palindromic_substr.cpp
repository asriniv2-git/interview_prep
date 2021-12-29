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

// Hint - Expand from center outwards for each index (diverging double pointer approach)

class Solution {
public:
    string longestPalindrome(string s) {
        int i, l, r;
        int len, start, end;
        int maxLen = 0;
        
        for (i = 0; i < s.size(); i++) {
            //detect odd length palindrome
            for (l = i, r = i; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                len = r - l + 1;  //Each match counts as a palindromic substring
                if (len > maxLen) {
                    start = l;
                    end = r;
                    maxLen = len;
                }
            }
            
            //detect even length palindrome
            for (l = i, r = i+1; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                len = r - l + 1;  //Each match counts as a palindromic substring
                if (len > maxLen) {
                    start = l;
                    end = r;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
