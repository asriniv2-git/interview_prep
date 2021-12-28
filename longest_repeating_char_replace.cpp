/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length */

// Explanation - sliding window approach with hash table, https://www.youtube.com/watch?v=gqXU1UyA8pk

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> numOccurences;
        map<char, int>::iterator it;
        int maxOccurences = 0;
        int i = 0;
        int j = 0;
        int len;
        int maxLength = 0;
        
        numOccurences[s[0]]++;  //Default setting for first window (0,0)
        
        while (j < s.size()) {
            len = j-i+1;  //Determine the length of the current window
            for (it = numOccurences.begin(); it != numOccurences.end(); it++) { //Determine max occurences of a single char in the window
                if (it->second > maxOccurences) {
                    maxOccurences = it->second;
                }
            }
            if ((len - maxOccurences) <= k) {  //Valid window, update max length and advance right pointer
                maxLength = max(len, maxLength);
                j++;
                numOccurences[s[j]]++;
            }
            else { //Invalid window, advance left poiner and remove occurence
                numOccurences[s[i]]--;
                i++;
            }
            maxOccurences = 0; //Reset before each new window
        }
        
        return maxLength;
    }
};
