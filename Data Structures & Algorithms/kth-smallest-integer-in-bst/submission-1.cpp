/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n {};
        vector<TreeNode*> theStack {};

        while(root || theStack.size() > 0){
            while(root){
                theStack.push_back(root);
                root = root->left;
            }
            root = theStack.back();
            theStack.pop_back();
            n++;
            if(n == k){
                return root->val;
            }
            root = root->right;
        }

        return theStack.back()->val;
    }
};
