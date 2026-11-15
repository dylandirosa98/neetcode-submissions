class TreeNode {
public:
    int key;
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key, int val){
        this->key = key;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class TreeMap {
private:
    TreeNode *root;

    TreeNode* findMin(TreeNode* root){
        TreeNode *curr = root;

        while(curr->left){
            curr = curr->left;
        }

        return curr;
    }

    TreeNode* removeHelper(TreeNode *root, int key){
        if(!root){
            return nullptr;
        }

        if(root->key > key){
            root->left = removeHelper(root->left, key);
        } else if(root->key < key){
            root->right = removeHelper(root->right, key);
        } else {
            if(!root->right){
                return root->left;
            } else if(!root->left){
                return root->right;
            }else{
                TreeNode *theMin = findMin(root->right);
                root->key = theMin->key;
                root->val = theMin->val;
                root->right = removeHelper(root->right, theMin->key);
            }
        }
        return root;
    }

    TreeNode* insertHelper(TreeNode *root, int key, int val){
        if(!root){
            return new TreeNode(key, val); 
        }

        if(root->key > key){
            root->left = insertHelper(root->left, key, val);
        } else if (root->key < key){
            root->right = insertHelper(root->right, key, val);
        }else{
            root->val = val;
        }

        return root;
    }

    void traverse(TreeNode *root, std::vector<int>& arr){
        if(!root){
            return;
        }

        traverse(root->left, arr);
        arr.push_back(root->key);
        traverse(root->right, arr);
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        root = insertHelper(root, key, val);
    }

    int get(int key) {
        TreeNode *curr = root;
        while(curr){
            if(curr->key > key){
                curr = curr->left;
            }else if (curr->key < key){
                curr = curr->right;
            }else{
                return curr->val;
            }
        }
        return -1;
    }

    int getMin() {
        TreeNode *curr = root;
        if(!curr){
            return -1;
        }
        while(curr->left){
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        TreeNode *curr = root;
        if(!curr){
            return -1;
        }
        while(curr->right){
            curr = curr->right;
        }
        return curr->val;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> keys {};
        traverse(root, keys);
        return keys;
    }
};
