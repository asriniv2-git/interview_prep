struct AVLNode {
    int       val;
    int       height;
    AVLNode  *left;
    AVLNode  *right;
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode *root;
public:
    AVLTree() {
        root = NULL;
    }
    
    int getHeight(AVLNode *node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }
    
    int getBalance(AVLNode *node) {
        if (node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    
    AVLNode* rightRotate(AVLNode *node) {
        AVLNode *temp1, *temp2;
        
        temp1 = node->left;
        temp2 = temp1->right;
        
        temp1->right = node;
        node->left = temp2;
        
        //Update heights
        temp1->height = max(getHeight(temp1->left), getHeight(temp1->right))+1;
        node->height = max(node->left->height, node->right->height)+1;
        
        return temp1;
    }
    
    AVLNode* leftRotate(AVLNode *node) {
        AVLNode *temp1, *temp2;
        
        temp1 = node->right;
        temp2 = temp1->left;
        
        temp1->left = node;
        node->right = temp2;
        
        //Update heights
        temp1->height = max(temp1->left->height, temp1->right->height)+1;
        node->height = max(node->left->height, node->right->height)+1;
        
        return temp1;
    }
    
    AVLNode* insert(AVLNode *node, int val) {
        int balance;
        
        if (node == NULL) {
            return new AVLNode(val);
        }
        
        if (val < node->val) {
            node->left = insertWord(node->left, val);    
        }
        else if (val > node->val) {
            node->right = insertWord(node->right, val);
        }
        else {
            return node; //Nothing to do for equal case
        }
        
        // Update height
        node->height = max(getHeight(node->left), getHeight(node->right))+1;

        // Get balance
        balance = getBalance(node);
        
        if (balance > 1 && val < node->left->val) { //Left left
            node = rightRotate(node);
        }
        else if (balance > 1 && val > node->left->val) { //Left right
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
        else if (balance < -1 && val > node->right->val) { //Right right
            node = leftRotate(node);
        }
        else if (balance < -1 && val < node->right->val) { //Right left
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
        
        return node;
    }
    
    bool search(AVLNode *node, int val) {        
        if (node == NULL) {
            return false;
        }
        
        if (val == node->val) {
            return true;
        }
        else if (val < node->val) {
            return search(node->left, val);
        }
        else {
            return search(node->right, val);
        }
    }
};
