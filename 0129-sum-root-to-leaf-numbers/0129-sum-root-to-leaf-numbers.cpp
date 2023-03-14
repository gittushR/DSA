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