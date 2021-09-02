/* Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, j;
        int length = 0;
        
        for (i = s.size()-1; i >= 0; i--) {
            if (s[i] != ' ') {
                break;    
            }
        }
        
        for (j = i; j >=0; j--) {
            if (s[j] == ' ') {
                break;
            }
            else {
                length++;
            }
        }
        
        return length;
    }
};
