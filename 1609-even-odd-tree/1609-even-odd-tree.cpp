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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=NULL) q.push(root);
        bool evenlevel=true;
        while(!q.empty()){   
            int size=q.size();
            TreeNode* prev=q.front();
            q.pop();
            if(evenlevel && prev->val%2==0) return false;
            if(!evenlevel && prev->val%2!=0) return false;
            if(prev->left!=NULL) q.push(prev->left);
            if(prev->right!=NULL) q.push(prev->right);
            for(int i=1;i<size;i++){
                TreeNode* curr=q.front();q.pop();
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                if(evenlevel && (curr->val<=prev->val || curr->val%2==0)) return false;
                if(!evenlevel && (curr->val>=prev->val || curr->val%2!=0)) return false;
                prev=curr;
            }
            evenlevel=!evenlevel;
        }
        return true;
    }
};