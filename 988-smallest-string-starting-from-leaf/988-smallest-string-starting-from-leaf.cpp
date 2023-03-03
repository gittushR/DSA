class Solution {
public:
    void solve(TreeNode* root , string ans , string &maxi){
        if(root == NULL)
            return;
        
        ans.push_back((char)(root->val +'a'));
        
        if(root->left == NULL && root->right == NULL){
            string str = ans;
            reverse(str.begin() , str.end());
            
            if(maxi == "" || str < maxi)
                maxi = str;
        }
        
        solve(root->left , ans , maxi);
        solve(root->right , ans , maxi);
        
        ans.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "" , maxi = "";
        solve(root, ans , maxi);
        return maxi;
    }
};