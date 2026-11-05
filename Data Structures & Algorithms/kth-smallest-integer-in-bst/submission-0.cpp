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
        vector<TreeNode*> stak {};
        
        while(root || !stak.empty()){
            
            while(root){
                stak.push_back(root);
                root = root->left;
            }
            root = stak.back();
            stak.pop_back();
            k--;
            if (k == 0){
                return root->val;
            }
            root = root->right;
        }

    }
};
