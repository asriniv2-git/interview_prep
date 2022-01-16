/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put. */

/*Approach
  1. Data structure - hash map to store key to value mapping, doubly linked list to store LRU status
  2. Hash map will map key to a node in the list containing value (and key)
  3. Head node is MRU, tail node is LRU
  4. 3 key conditions to be handled during put
     - Key is already in the map (updateNode()) - just update value and node status to MRU (head)
     - Key not in the map but capacity reached (evictNode())- evict LRU node, add new node for (key, val) pair and update status to MRU
     - Key not in the map and space available (addNode()) - add new node for (key, val) pair and update status to MRU
      
  Complexity
  O(1) - Updating list and retrieving (key, value) from an UNORDERED map are both constant time operations */

struct lNode {
    int key;
    int val;
    struct lNode *next;
    struct lNode *prev;
    lNode(int x, int y): key(x), val(y), next(NULL), prev(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, struct lNode *> hash;
    int size;
    struct lNode *head;
    struct lNode *tail;
    
    void addNode(struct lNode *node) {
        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    
    int evictNode() {
        int key;
        
        key = tail->key;
        if (head == tail) {
            delete(head);
            head = NULL;
            tail = NULL;
        }
        else {
            struct lNode *node = tail->prev;
            delete(tail);
            node->next = NULL;
            tail = node;
        }
        return key;
    }
    
    void updateNode(struct lNode *node, int value) {
        struct lNode *next, *prev;
        
        node->val = value;
        if (node == head) {
            return;  //Nothing to be done
        }
        // Break and update node links, update tail if necessary
        prev = node->prev;
        next = node->next;
        prev->next = next;
        if (next != NULL) {
            next->prev = prev;
        }
        else {
            tail = prev; //New tail
        }
        // Make node the new head
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;  //Key node not found
        }
        updateNode(hash[key], hash[key]->val);
        return hash[key]->val;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            updateNode(hash[key], value); 
        }
        else {
            if (hash.size() == size) {
                hash.erase(evictNode()); //Remove LRU node
            }    
            hash[key] = new lNode(key, value);
            addNode(hash[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
