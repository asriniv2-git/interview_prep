/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000*/

/* Truth table
A     B     Sum   Carry
0     0     0     0
0     1     1     0
1     0     1     0
1     1     0     1
*/

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        
        while ( b != 0 )
        {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;            
        }
        return a;
    }
};

/* Bitwise subtract */

/* Truth table 
X     Y     Diff  Borrow
0     0     0     0
0     1     1     1
1     0     1     0
1     1     0     0
*/

class Solution {
public:
    int getSum(int a, int b) {
        int borrow;
        
        while ( b != 0 )
        {
            borrow = (~a) & b;
            a = a ^ b;
            b = borrow << 1;            
        }
        return a;
    }
};
