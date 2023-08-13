// class Solution {
// public:
//     bool helper(vector<int> nums, int ind,vector<int> &dp){
//         int n= nums.size();
//         if(ind==nums.size())return true;
//         if(dp[ind]!=-1)return dp[ind];
//         if(ind+1<n and nums[ind]==nums[ind+1]){
//             if(helper(nums,ind+2,dp))return dp[ind]=true;
//         }
//         if(ind+2<n and nums[ind]==nums[ind+1] and nums[ind]==nums[ind+2]){
//             if(helper(nums,ind+3,dp))return dp[ind]=true;
//         }
//         if(ind+2<n and nums[ind]+1==nums[ind+1] and nums[ind]+2==nums[ind+2]){
//             if(helper(nums,ind+3,dp))return dp[ind]=true;
//         }
//         return dp[ind]=false;
//     }
//     bool validPartition(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,-1);
//         return helper(nums,0,dp);
//     }
// };
class Solution
{
public:
    bool c(vector<int> &v, vector<int> &dp, int i)
    {
        int n = v.size();
        if (i == v.size())
            return true;
        if (dp[i] != -1)
            return dp[i];

        if (i + 1 < n && v[i] == v[i + 1])
        {
            if (c(v, dp, i + 2))
                return dp[i] = true;
        }

        if (i + 2 < n && v[i] == v[i + 2] and v[i] == v[i + 1])
        {
            if (c(v, dp, i + 3))
                return dp[i] = true;
        }
        if (i + 2 < n && v[i] + 1 == v[i + 1] && v[i] + 2 == v[i + 2])
        {
            if (c(v, dp, i + 3))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, -1);
        return c(v, dp, 0);
    }
};