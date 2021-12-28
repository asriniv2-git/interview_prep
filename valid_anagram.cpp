/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters. */

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hash;
        map<char, int>::iterator it;
        int i;
        
        for (i = 0; i < s.size(); i++) {
            hash[s[i]]++;
        }
        
        for (i = 0; i < t.size(); i++) {
            if (!hash[t[i]]) {
                return false;
            }
            hash[t[i]]--;
        }
        
        for (it = hash.begin(); it != hash.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        
        return true;
    }
};
