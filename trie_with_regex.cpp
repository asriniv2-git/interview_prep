/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search. */

class TrieNode {
private:
    TrieNode *links[26];
    bool      isEnd;
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        isEnd = false;
    }
    bool containsKey(char c) {
        return (links[c - 'a'] != NULL);
    }
    void setKey(char c, TrieNode *node) {
        links[c - 'a'] = node;
    }
    TrieNode* getKey(char c) {
        return links[c - 'a'];
    }
    void setEnd() {
        isEnd = true;
    }
    bool getEnd() {
        return isEnd;
    }    
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node;
        
        node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->setKey(word[i], new TrieNode);
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
        return;
    }
    
    bool searchWord(string word, int index, TrieNode *node) {
        if (index == word.size()) {
            return node->getEnd();
        }
        
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->containsKey(i+'a')) {
                    if (searchWord(word, index+1, node->getKey(i+'a'))) {
                        return true;
                    }
                }
            }
            return false;
        }
        
        if (!node->containsKey(word[index])) {
            return false;
        }
            
        return searchWord(word, index+1, node->getKey(word[index]));
    }
                          
    bool search(string word) {
        TrieNode *node;
        
        node = root;
        
        return searchWord(word, 0, node);
    }
};
