class Solution {
public:
    int f(int ind,vector<int>&dp,vector<int> nums){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int rob=nums[ind]+f(ind+2,dp,nums);
        int notRob=0+f(ind+1,dp,nums);
        return dp[ind]=max(rob,notRob);
        }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,dp,nums);
    }
};