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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int max_level=1;
        int curr_level=1;
        int curr_sum=0;
        int max_sum=INT_MIN;
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top==NULL){
                if(q.empty()){
                    if(curr_sum>max_sum){
                        return curr_level;
                    }
                }else{
                    if(curr_sum>max_sum){
                        max_sum=curr_sum;
                        max_level=curr_level;
                    }
                    curr_sum=0;
                    curr_level++;
                    q.push(NULL);
                }
                
            }else{
            curr_sum+=top->val;
            if(top -> left != NULL){
                q.push(top -> left);
            }
            if(top -> right != NULL){
                q.push(top -> right);
            }
            }
        }
        return max_level;
    }
};