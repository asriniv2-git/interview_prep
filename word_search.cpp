/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.*/

// Explanation - https://www.youtube.com/watch?v=pfiQ_PS1g8E

class Solution {
public:
    vector<pair<int, int>> path;  //Tracks the characters visited during a dfs path to prevent revisiting
    
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        int found = 0;
        
        for (i = 0; i < board.size(); i++) {
            for (j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string word) {
        vector<pair<int, int>>::iterator it;
        bool res;
        
        if (idx == word.size()) {
            return true;
        }
        
        it = find(path.begin(), path.end(), make_pair(i, j));
        
        if ((i < 0 || i >= board.size())    || 
            (j < 0 || j >= board[0].size()) ||
            (board[i][j] != word[idx])      || 
            (it != path.end())              ) {  //Last condition ensures an already traversed character is not being revisited
            return false;
        }
        
        path.push_back(make_pair(i, j)); // Match found, add itself to traversed path
        
        res = dfs(i+1, j, idx+1, board, word) || 
              dfs(i-1, j, idx+1, board, word) || 
              dfs(i, j+1, idx+1, board, word) || 
              dfs(i, j-1, idx+1, board, word); //Check neighbouring characters
        
        path.pop_back(); //Done processing, remove itself from traversed path
        
        return res;
    }
};
