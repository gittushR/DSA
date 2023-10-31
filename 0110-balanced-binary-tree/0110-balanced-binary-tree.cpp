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
    int height(TreeNode * node){
        if(!node)return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        if(!root->left&&!root->right)return true;
        int heightl=height(root->left);
        int heightr=height(root->right);
        if(abs(heightl-heightr)<=1 && isBalanced(root->left) && isBalanced(root->right))return true;
        return false;
    }
};