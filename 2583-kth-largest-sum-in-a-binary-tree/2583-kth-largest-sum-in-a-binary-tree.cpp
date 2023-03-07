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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> sums;
        q.push(root);
        while(!q.empty()){
            long long curr_sum=0;
            long long t=q.size();

            for(int i=0;i<t;i++){
                TreeNode* node=q.front();
                q.pop();
                
                curr_sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            sums.push_back(curr_sum);
        }
        sort(sums.begin(),sums.end());
        if(sums.size()<k)return -1;
        
        return sums[sums.size()-k];
    }
};