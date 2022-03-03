/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'. */

/*  Approach
    Standard algorithm
    Maintain a global counter (for result) and one for tracking open brackets
    Iterate through string
    On every open bracket, increment open_bra (or add to a stack)
    On every close bracket, check status of open_bra
    - If > 0 -> there is a matching open bracket, decrement open_bra
    - Else -> no matching open bracket, need to add one so increment global counter
    End of loop, result is open_bra+count
       
    Complexity
    Time - O(n)
    Space - O(1) */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_bra = 0;
        int count = 0;
        
        for (auto &c : s) {
            if (c == '(') {
                open_bra++;
            }
            else if (c == ')') {
                if (open_bra) {
                    open_bra--;
                }
                else {
                    count++;
                }
            }
        }
        
        return (open_bra+count);
    }
};
