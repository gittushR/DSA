class Solution {
  public:
    bool validator(Node* root, int minVal , int maxVal){
        if(root==nullptr)return true;
        if(root->data>=maxVal or root->data<=minVal)return false;
        return validator(root->left,minVal,root->data) and validator(root->right,root->data,maxVal);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        if (root==nullptr) return true;
        return validator(root,INT_MIN,INT_MAX);
    }
};