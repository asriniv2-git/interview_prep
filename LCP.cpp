/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        int pos;
        string str;
        
        pos = strs[0].size();
        
        while (pos != 0) {
            str = strs[0].substr(0, pos-1);
            for (i = 1; i < strs.size(); i++) {
                if (equal(str.begin(), str.end(), strs[i].begin()) != true) {
                    break;
                }
            }
            if (i == strs.size()) {
                return str;
            }
            pos--;
        }
        return "";
    }
};
