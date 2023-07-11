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
private:
    void track_parent(TreeNode*root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    void findStart(TreeNode* root,int start, TreeNode* &starting){
        if(!root)return;
        findStart(root->left,start,starting);
        if(root->val==start){
            starting=root;
            return;
        }
        findStart(root->right,start,starting);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parent;
        track_parent(root,parent);
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        TreeNode* starting;
        findStart(root,start,starting);
        q.push({starting,0});
        visited[starting]=true;
        int t=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* current=it.first;
                int time=it.second;
                if(current->left && !visited[current->left]) {
                    q.push({current->left,time+1});
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    q.push({current->right,time+1});
                    visited[current->right] = true;
                }
                if(parent[current] && !visited[parent[current]]) {
                    q.push({parent[current],time+1});
                    visited[parent[current]] = true;
                }
                t=max(t,time);
            }
        }
        return t;
    }
};