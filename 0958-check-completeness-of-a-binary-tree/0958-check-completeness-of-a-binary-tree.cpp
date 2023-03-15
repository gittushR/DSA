class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)return true;
        queue<TreeNode*>q;q.push(root);
        bool sonu = false ;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                sonu = true ;
            }
            else{
                if(sonu)return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};