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

        if (root){
            q.push(root);
        }

        while(q.size()>0){
            vector<int> idk {};
            int size {static_cast<int>(q.size())};
            for(int i{}; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                idk.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            answer.push_back(idk);
        }
        return answer;
    }
};
