/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104 */

// Explanation - https://www.youtube.com/watch?v=g9YQyYi4IQQ

class Solution {
public:
    double myPow(double x, int n) {
        int pow;
        double res;
        
        res = computePow(x, abs(n));
        
        if (n >= 0) {
            return res;
        }
        else {
            return 1/res;
        }
    }
    
    double computePow(double x, int pow) {
        double res;
        
        if (x == 0 || pow == 1) {
            return x;
        }
        if (pow == 0) {
            return 1;
        }
        
        res = computePow(x, pow/2); //Recursive, divide and conquer - O(logn)
        if ((pow % 2) == 0) {
            res = res*res;
        }
        else {
            res = x*res*res;
        }
        
        return res;
    }
};
