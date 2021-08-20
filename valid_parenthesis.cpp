/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> open_bra;
        int i;
        
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open_bra.push_back(s[i]);
            }
            else if (!open_bra.empty()                         &&
                     ((s[i] == ')' && open_bra.back() == '(')  ||
                      (s[i] == '}' && open_bra.back() == '{')  ||
                      (s[i] == ']' && open_bra.back() == '['))) {
                open_bra.pop_back();        
            }
            else {
                return false;
            }
        }
        
        if (open_bra.empty()) {
            return true;
        }
        else {
            return false;
        }
        
    }
};
