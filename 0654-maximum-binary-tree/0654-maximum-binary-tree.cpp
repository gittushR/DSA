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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root= construct(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* construct(vector<int>&arr, int start, int end){
        if(start > end)return NULL;
        if(start == end)return new TreeNode(arr[start]);
        
        int rootInd= findRoot(arr, start, end);
        TreeNode* root= new TreeNode(arr[rootInd]);
        root->left=construct(arr,start,rootInd-1);
        root->right=construct(arr,rootInd+1,end);
        return root;
    }
    int findRoot(vector<int>&arr, int s, int e){
        int max=-1e9;
        int ind=-1;
        for(int i=s;i<=e;i++){
            if(arr[i]>max){
                max=arr[i];
                ind=i;
            }
        }
        return ind;
    }
};