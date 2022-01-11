/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith. */

//Explanation - https://leetcode.com/problems/implement-trie-prefix-tree

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

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        TrieNode *node;
        
        node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->getKey(word[i]);
        }
        
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode *node;
        
        node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getKey(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
