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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q {};
        vector<vector<int>> answer {};
        std::queue<TreeNode*> newq {};

        if(root){
            q.push(root);
        }

        while(!q.empty()){
            int length = q.size();
            vector<int> row {};
            for(int i {}; i < length; i++){
                TreeNode* curr = q.front();
                q.pop();
                row.push_back(curr->val);
                if(curr->left){
                    newq.push(curr->left);
                }
                if(curr->right){
                    newq.push(curr->right);
                }
            }
            q = newq;
            newq = {};
            answer.push_back(row);
        }
        return answer;
    }
};
