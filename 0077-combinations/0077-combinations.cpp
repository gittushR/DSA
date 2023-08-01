class Solution {
public:
    void helper(int t,vector<int> &temp, vector<vector<int>> &ans, int n,int k){
        if(t==n+1){
            if(temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }
        //pick
        temp.push_back(t);
        helper(t+1,temp,ans,n,k);
        //notpick
        temp.pop_back();
        helper(t+1,temp,ans,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,temp,ans,n,k);
        return ans;
    }
};