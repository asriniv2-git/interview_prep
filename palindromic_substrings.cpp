/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters. */

// Use expand around center approach as in longest_palindromic_substring.cpp

class Solution {
public:
    int countSubstrings(string s) {
        int i, l, r, len;
        int res = 0;
        
        for (i = 0; i < s.size(); i++) {
            //detect odd length palindromes
            for (l = i, r = i; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                res++;  //Each match counts as a palindromic substring
            }
            
            //detect even length palindromes
            for (l = i, r = i+1; l >= 0 && r < s.size(); l--, r++) {
                if (s[l] != s[r]) {
                    break;
                }
                res++;
            }
        }
        
        return res;
    }
};
