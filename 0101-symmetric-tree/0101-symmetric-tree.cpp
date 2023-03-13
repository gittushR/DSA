class Solution {
public:
    bool helper(TreeNode*lefttree,TreeNode*righttree){
        if(lefttree==NULL && righttree==NULL) return true;
        if(lefttree==NULL || righttree==NULL) return false;
        if(lefttree->val!=righttree->val)return false;
        return (helper(lefttree->left,righttree->right))&&(helper(lefttree->right,righttree->left));
    }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)return true;
        return helper(root->left,root->right);
    }
};