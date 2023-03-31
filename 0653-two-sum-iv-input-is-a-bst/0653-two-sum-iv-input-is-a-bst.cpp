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
    void getArr(TreeNode* root, vector<int> &arr){
        if(!root)return;
        getArr(root->left,arr);
        arr.push_back(root->val);
        getArr(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        getArr(root,arr);
        int n=arr.size();
        int s=0,e=n-1;
        while(s<e){
            if(arr[s]+arr[e]==k)return true;
            else if((arr[s]+arr[e])>k)e--;
            else s++;
        }
        return false;
    }
};