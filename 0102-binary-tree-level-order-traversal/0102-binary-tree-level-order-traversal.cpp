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
        vector<vector<int>> levels;
        vector<int> level;
        if(!root)return levels;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it==NULL){
                levels.push_back(level);
                level.clear();
                if(q.empty())break;
                else q.push(NULL);
            }else{
                level.push_back(it->val);
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
        }
        return levels;
    }
};