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
    vector<vector<int>> pathSum(TreeNode* root, int s) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,ans,temp,0,s);
        return ans;
    }
    void helper(TreeNode* root, vector<vector<int>> &ans, vector<int> &temp, int curr, int s){
        if(!root)return;
        temp.push_back(root->val);
        curr+=root->val;
        if(!root->left && !root->right){
            if(curr==s)ans.push_back(temp);
        }
        helper(root->left,ans,temp,curr,s);
        helper(root->right,ans,temp,curr,s);
        curr-=root->val;
        temp.pop_back();
        return;
    }
};