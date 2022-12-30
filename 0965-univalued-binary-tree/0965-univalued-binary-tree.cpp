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
bool ans=true;
void solve(TreeNode* root, int value)
{
if(root==NULL)
{
return;
}
if(root->val!=value)
{
ans=false;
}
solve(root->left,value);
solve(root->right,value);
}
bool isUnivalTree(TreeNode* root) {
if(root!=NULL)
solve(root,root->val);
return ans;
}
};