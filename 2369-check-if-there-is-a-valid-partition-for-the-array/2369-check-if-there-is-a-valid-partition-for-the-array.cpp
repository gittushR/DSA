class Solution {
public:
    bool helper(vector<int>&nums, int ind,vector<int> &dp){
        int n= nums.size();
        if(ind==nums.size())return true;
        if(dp[ind]!=-1)return dp[ind];
        if(ind+1<n and nums[ind]==nums[ind+1]){
            if(helper(nums,ind+2,dp))return dp[ind]=true;
        }
        if(ind+2<n and nums[ind]==nums[ind+1] and nums[ind]==nums[ind+2]){
            if(helper(nums,ind+3,dp))return dp[ind]=true;
        }
        if(ind+2<n and nums[ind]+1==nums[ind+1] and nums[ind]+2==nums[ind+2]){
            if(helper(nums,ind+3,dp))return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,0,dp);
    }
};