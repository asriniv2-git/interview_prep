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

/* Solution 1 - Horizontal scanning */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i;
        int pos;
        string str;
        
        if (strs.size() == 0) return "";
        else if (strs.size() == 1) return strs[0];
        
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

/* Solution 2 - Vertical scanning */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j;
        char c;
        
        if (strs.size() == 0) return "";
        else if (strs.size() == 1) return strs[0];
        
        for (i = 0; i < strs[0].size(); i++) {
            c = strs[0][i];
            for (j = 1; j < strs.size(); j++) {
                if  ((i >= strs[j].size()) || (c != strs[j][i])) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
