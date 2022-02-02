/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters. */

class Solution {
private:
    bool isMismatch = false;
public:
    bool validPalindrome(string s) {        
        int i, j;
        bool isMismatch = false;
        
        i = 0;
        j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (isMismatch) {
                    break;  //2nd mismatch, try moving right
                }
                j--; //One mismatch allowed, move left
                isMismatch = true;
                continue;
            }
            i++;
            j--;
        }
        
        if (i >= j) {
            return true;   //Palindrome found
        }
        
        //No palindrome, move right on first mismatch
        i = 0;
        j = s.size()-1;
        isMismatch = false;   
        while (i < j) {
            if (s[i] != s[j]) {
                if (isMismatch) {
                    return false;
                }
                i++; //Move right
                isMismatch = true;
                continue;
            }
            i++;
            j--;
        }
        
        return true; //Palindrome found
    }
};
