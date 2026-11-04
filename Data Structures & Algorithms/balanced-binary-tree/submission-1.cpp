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
    bool isBalanced(TreeNode* root) {
       return dfs(root).balance; 
    }

private:
    struct DfsAns{
        bool balance;
        int height;
    };

    DfsAns dfs(TreeNode* root){
        if(!root){
            return DfsAns{true, 0};
        }

        DfsAns left = dfs(root->left);
        DfsAns right = dfs(root->right);

        bool balance {false};
        if(abs(left.height-right.height) <= 1 && left.balance && right.balance){
            balance = true;
        }

        return DfsAns{balance, 1 + max(left.height, right.height)};
    }
};
