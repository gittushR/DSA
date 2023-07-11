class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int ind=1;ind<n;ind++){
            int steps=INT_MIN;
            for(int i=ind-1;i>=0;i--){
                if(abs(nums[ind]-nums[i])<=target){
                    steps=max(steps,1+dp[i]);
                }
            }
            dp[ind]=steps;
        }
        int ans=dp[n-1];
        return ans>0?ans:-1;
    }
};