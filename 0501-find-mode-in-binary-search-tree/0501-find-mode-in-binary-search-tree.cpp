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
    void inorder(TreeNode *root, map<int,int> &mp){
        if (root==NULL)return;
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return ans;
        }
        map<int, int> mp;
        inorder(root, mp);
        priority_queue<pair<int,int>> pq;
        for(auto [a,b]:mp){pq.push({b,a});}
        ans.push_back(pq.top().second);
        int n=pq.top().first;
        pq.pop();
        while(!pq.empty()){
        if(pq.top().first==n){
            ans.push_back(pq.top().second);
        }
            pq.pop();
        }
        return ans;
    }
};