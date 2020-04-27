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
    bool isValid(string str) {
        vector<char> open_bra;
        int i;
        
        for (i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                open_bra.push_back(str[i]);
            }
            else if (str[i] == ')') {
                if (open_bra.back() == '(') {
                    open_bra.pop_back();
                }
                else {
                    return false;
                }
            }
            else if (str[i] == '}') {
                if (open_bra.back() == '{') {
                    open_bra.pop_back();
                }
                else {
                    return false;
                }
            }
            else if (str[i] == ']') {
                if (open_bra.back() == '[') {
                    open_bra.pop_back();
                }
                else {
                    return false;
                }
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
