class Solution {
    bool helper(int idx, vector<int> &nums, int take, int sum, vector<vector<int>> &dp){
        if(idx==nums.size() or 2*take==sum) return 2*take==sum;
        if(2*(take+nums[idx])<=sum){
            if(dp[idx][take+nums[idx]]==-1) dp[idx][take+nums[idx]] = helper(idx+1, nums, take+nums[idx], sum, dp);
            if(dp[idx][take+nums[idx]]) return true;
        }
        if(dp[idx][take]==-1) dp[idx][take] = helper(idx+1, nums, take, sum, dp);
        return dp[idx][take];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it : nums) sum+=it;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum, -1));
        return helper(0, nums, 0, sum, dp);
    }
};