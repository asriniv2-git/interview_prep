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
        std::string str;
        int mod, div;
        int num;
        long long result;
        
        if (x < 0) {
            num = x*-1;
        }
        else {
            num = x;
        }

        div = num/10;
        mod = num%10;
        str.append(std::to_string(mod));
        while (div != 0) {
            mod = div%10;
            str.append(std::to_string(mod));
            div = div/10;
        }

        result = std::stoll(str);
        if (x < 0) {
            result *= -1;
        }

        if ((result > (pow(2,31) - 1)) || (result < -pow(2,31))) {
            return 0;
        }
        else {
            return (int)result;
        } 
    }
};
