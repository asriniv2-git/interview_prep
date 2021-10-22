/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        
        for (i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        
        j = i-1;
        i = 0;     
        while(i < j) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
            else if(!isalnum(s[i]) && !isalnum(s[j])) {
                i++;
                j--;
            }
            else if (isalnum(s[i]) && !isalnum(s[j])) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return true;
    }
};
