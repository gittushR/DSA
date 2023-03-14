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
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int sum=0;
        int curr=0;
        getsum(root,curr,sum);
        return sum;
    }
    void getsum(TreeNode *root, int &curr, int &sum){
        if(!root)return;
        curr=curr*10+root->val;
        if(!root->left && !root->right)sum+=curr;
        getsum(root->left,curr,sum);
        getsum(root->right,curr,sum);
        curr/=10;
    }
};