/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter. */

/*  Approach
    Traverse through string
    If letter, add to temp string
    If (, increment open count and add to temp string
    If ), check open count
        If > 0, decrement and add to temp string
        else skip
        
    If open count == 0, return temp string
    
    Else traverse temp string backwards from end
       If ( and open count > 0, skip and decrement
       else add to result string
    Reverse result string and return
       
    Complexity
    Time - 2 linear travsersals plus reverse, O(n+n+n) = O(n)
    Space - temp and result string, O(n+n) = O(n) */
           
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open_bra = 0;
        string temp, res;
        int i;
        
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                temp.push_back(s[i]);
                open_bra++;
            }
            else if (s[i] == ')') {
                if (open_bra) {
                    temp.push_back(s[i]);
                    open_bra--;
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }
        
        if (open_bra == 0) {
            return temp;
        }
        
        for (i = temp.size()-1; i >= 0; i--) {
            if (temp[i] == '(' && open_bra) {
                open_bra--;
            }
            else {
                res.push_back(temp[i]);
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
