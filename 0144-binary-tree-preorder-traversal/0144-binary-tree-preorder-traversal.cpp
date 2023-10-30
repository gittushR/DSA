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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(!root)return preOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            preOrder.push_back(it->val);
            if(it->right)st.push(it->right);
            if(it->left)st.push(it->left);
        }
        return preOrder;
    }
};