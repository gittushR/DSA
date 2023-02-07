class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> v;
    vector<int> temp;
    queue<TreeNode*> q;
    if(root==NULL){return v;}
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        if (f == NULL)
        {
            v.push_back(temp);
            temp.clear();
            if(!q.empty()){q.push(NULL);}

        }
        else
        {
            temp.push_back(f->val);
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
        for(int i=1;i<v.size();i=i+2){
            reverse(v[i].begin(),v[i].end());
        }
    
    return v;
    }
};