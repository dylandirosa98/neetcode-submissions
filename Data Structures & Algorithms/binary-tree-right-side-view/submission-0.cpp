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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer {};
        std::queue<TreeNode*> q{};
        std::queue<TreeNode*> newq{};

        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int rownum{};
            int length = q.size();
            for(int i{}; i < length; i++){
                TreeNode* curr = q.front();
                q.pop();
                rownum = curr->val;
                if(curr->left){
                    newq.push(curr->left);
                }
                if(curr->right){
                    newq.push(curr->right);
                }
            }
            answer.push_back(rownum);
            q = newq;
            newq = {};
        }
        return answer;
    }
};
