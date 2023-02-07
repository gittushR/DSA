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
        if(!root)return levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode * Node=q.front();
                q.pop();
                temp.push_back(Node->val);
                if( Node->left)q.push(Node->left);
                if(Node->right)q.push(Node->right);
            }
            levels.push_back(temp);
            temp.clear();
        }
        return levels;
    }
};