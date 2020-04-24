/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int rem;
        int intmax, intmin;
        
        intmax = pow(2,31)-1;
        intmin = -pow(2,31);
        
        while (x != 0) {
            rem = x%10;
            x = x/10;
            if (result > intmax/10 || (result == intmax/10 && rem > 7) ||
                result < intmin/10 || (result == intmin/10 && rem < -8)) {
                return 0;
            }
            result = result*10 + rem;
        }
        
        return result; 
    }
};
