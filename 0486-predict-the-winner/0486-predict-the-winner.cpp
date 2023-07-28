class Solution {
public:
    int dfs(int ind1, int ind2, vector<int> nums,int turn,vector<vector<vector<long>>> &dp){
        if(ind1==nums.size() or ind2==-1)return 0;
        if(ind1>ind2)return 0;
        if(dp[ind1][ind2][turn]!=-1e10)return dp[ind1][ind2][turn];
        if(turn==0){
            return dp[ind1][ind2][turn]=max(nums[ind1]+dfs(ind1+1,ind2,nums,1,dp),nums[ind2]+dfs(ind1,ind2-1,nums,1,dp));
        }else{
            return dp[ind1][ind2][turn]= min(-nums[ind1]+dfs(ind1+1,ind2,nums,0,dp),-nums[ind2]+dfs(ind1,ind2-1,nums,0,dp));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<long>>> dp(n,vector<vector<long>>(n,vector<long>(2,-1e10)));
        int value=dfs(0,n-1,nums,0,dp);
        return value>=0;
    }
};