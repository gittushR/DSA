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
    int count = 0;
    void parentSum(TreeNode* root, long long sum){
        if(!root) return;
        if(sum == root->val) count++;
        parentSum(root->left, sum - root->val);
        parentSum(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            parentSum(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return count;
    }
};