class Solution {
public:
    bool f(int ind, int target,vector<int>& nums, vector<vector<int>>&dp){
        if(ind==0)return (target==nums[0]);
        if(target==0)return true;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notTake=f(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind])take=f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=(take or notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return f(n-1,sum/2,nums,dp);
    }
};