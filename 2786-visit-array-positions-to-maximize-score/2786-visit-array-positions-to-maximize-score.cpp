class Solution {
public:
    long long fn(int ind,int p, vector<int> nums, int n, int x,vector<vector<int>> &dp){
        if(ind==n)return 0;
        if(dp[ind][p]!=-1)return dp[ind][p];
        long long notTake=fn(ind+1,p,nums,n,x,dp);
        long long take=nums[ind]+fn(ind+1,nums[ind]%2,nums,n,x,dp);
        if (nums[ind] % 2 != p) take -= x;
        return dp[ind][p]=max(take,notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        int par;
        if(nums[n-1]%2==0)par=0;
        else par=1;
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int p=0;p<=1;p++){
                long long notTake=dp[ind+1][p];
                long long take=nums[ind]+dp[ind+1][nums[ind]%2];
                if (nums[ind] % 2 != p) take -= x;
                dp[ind][p]=max(take,notTake);
            }
        }
        return dp[0][nums[0]%2];
    }
};