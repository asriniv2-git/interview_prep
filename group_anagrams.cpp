/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters. */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i, j;
        map<char, int> key;
        map<map<char, int>, vector<string>> hash;
        map<map<char, int>, vector<string>>::iterator it;
        vector<vector<string>> res; 
        
        for (i = 0; i < strs.size(); i++) {
            for (j = 0; j < strs[i].size(); j++) { // Create a map for each string which forms the "key" to a map of grouped anagram strings
                key[strs[i][j]]++;
            }
            hash[key].push_back(strs[i]);
            key.clear();
        }
        
        for (it = hash.begin(); it != hash.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};
