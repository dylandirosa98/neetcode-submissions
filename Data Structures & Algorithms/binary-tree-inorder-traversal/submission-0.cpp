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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer = {};
        traversal(root, answer);
        return answer;
    }

private:
    void traversal(TreeNode* root, vector<int>& answer){
        if(!root){
            return;
        }
        traversal(root->left, answer);
        answer.push_back(root->val);
        traversal(root->right, answer);
    }
};