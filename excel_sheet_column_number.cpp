/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i;
        int j = 0;
        int res = 0;
        
        for (i = columnTitle.size()-1; i >= 0; i--) {
            res += pow(26,j)*(columnTitle[i]-'A'+1);
            j++;
        }
        
        return res;
    }
};
