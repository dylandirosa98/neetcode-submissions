#include <vector>

// 1. TreeNode class properly declared and closed
class TreeNode {
public:
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int val)
        : key(key), val(val), left(nullptr), right(nullptr) {}

    TreeNode(int key, int val, TreeNode* left, TreeNode* right)
        : key(key), val(val), left(left), right(right) {}
}; // Closed TreeNode

// 2. TreeMap class wraps root and all operations
class TreeMap {
private:
    TreeNode* root;

    // Helper to find the smallest node in a subtree (used by remove & getMin)
    TreeNode* findMin(TreeNode* curr) {
        while (curr != nullptr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    // Helper for recursive removal
    TreeNode* removeHelper(TreeNode* curr, int key) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (key < curr->key) {
            curr->left = removeHelper(curr->left, key);
        } else if (key > curr->key) {
            curr->right = removeHelper(curr->right, key);
        } else {
            // Found node to delete: 0 or 1 child
            if (curr->left == nullptr) {
                return curr->right;
            } else if (curr->right == nullptr) {
                return curr->left;
            } else {
                // 2 children: swap with inorder successor, then delete successor
                TreeNode* successor = findMin(curr->right);
                curr->key = successor->key;
                curr->val = successor->val;
                curr->right = removeHelper(curr->right, successor->key);
            }
        }
        return curr;
    }

    // Helper for recursive inorder traversal
    void inorderHelper(TreeNode* curr, std::vector<int>& result) {
        if (curr == nullptr) {
            return;
        }
        inorderHelper(curr->left, result);
        result.push_back(curr->key);
        inorderHelper(curr->right, result);
    }

public:
    TreeMap() : root(nullptr) {}

    void insert(int key, int val) {
        TreeNode* newNode = new TreeNode(key, val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* curr = root;
        while (true) {
            if (key < curr->key) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            } else if (key > curr->key) {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            } else {
                // Key already exists: update value and discard unused node
                curr->val = val;
                delete newNode;
                return;
            }
        }
    }

    int get(int key) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (key < curr->key) {
                curr = curr->left;
            } else if (key > curr->key) {
                curr = curr->right;
            } else {
                return curr->val;
            }
        }
        return -1;
    }

    int getMin() {
        TreeNode* minNode = findMin(root);
        return (minNode != nullptr) ? minNode->val : -1;
    }

    int getMax() {
        if (root == nullptr) {
            return -1;
        }
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        return curr->val;
    }

    void remove(int key) {
        root = removeHelper(root, key);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};
