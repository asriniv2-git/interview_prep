/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i;
        int num_a = 0;
        int num_b = 0;
        int sum;
        string res;
        
        for (i = 0; i < a.size(); i++) {
            num_a = num_a<<1 | (a[i]-48);    
        }
        for (i = 0; i < b.size(); i++) {
            num_b = num_b<<1 | (b[i]-48);    
        }
        
        sum = num_a + num_b;
        
        if (sum == 0) {
            res.insert(res.begin(),48);
        }
        while (sum != 0) {
            res.insert(res.begin(), (sum&1)+48);
            sum = sum>>1;
        }
        
        return res;
    }
};
