/*
iven a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.*/

class Solution {
public:
    // O(n) space solution
    int calculate(string s) {
        int i;
        int currentNum = 0;
        int prevNum;
        char prevOp = '+';
        stack<int> res;
        
        for (i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                currentNum = currentNum*10 + (s[i]-'0');
            }
            if ((!isdigit(s[i]) && (s[i] != ' ')) || (i == s.size()-1)) {
                if (prevOp == '+') {
                    res.push(currentNum);
                }
                else if (prevOp == '-') {
                    res.push(-1*currentNum);
                }
                else if (prevOp == '*') {
                    prevNum = res.top();
                    res.pop();
                    res.push(prevNum*currentNum);
                }
                else if (prevOp == '/') {
                    prevNum = res.top();
                    res.pop();
                    res.push(prevNum/currentNum);
                }
                prevOp = s[i];
                currentNum = 0;
            }       
        }
                   
        while (!res.empty()) {
            currentNum += res.top();
            res.pop();
        }
                    
        return currentNum;
    }
    
    // O(1) space solution
    int calculate(string s) {
        int i;
        int currentNum = 0;
        int prevNum;
        char prevOp = '+';
        int res = 0;
        
        for (i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                currentNum = currentNum*10 + (s[i]-'0');
            }
            if ((!isdigit(s[i]) && (s[i] != ' ')) || (i == (s.size()-1))) {
                if (prevOp == '+') {
                    res += currentNum;
                    prevNum = currentNum;
                }
                else if (prevOp == '-') {
                    res -= currentNum;
                    prevNum = -1*currentNum;
                }
                else if (prevOp == '*') {
                    res -= prevNum;
                    res += prevNum*currentNum;
                    prevNum = prevNum*currentNum;
                }
                else if (prevOp == '/') {
                    res -= prevNum;
                    res += prevNum/currentNum;
                    prevNum = prevNum/currentNum;
                }
                prevOp = s[i];
                currentNum = 0;
            }       
        }
                    
        return res;
    }
};
