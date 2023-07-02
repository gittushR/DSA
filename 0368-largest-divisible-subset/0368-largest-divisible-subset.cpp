class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int>hash(n);
        sort(nums.begin(),nums.end());
        int maxi=1;
        int lastIndex=0;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]%nums[prev_ind]==0 and 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }
        vector<int> lds;
        while(hash[lastIndex]!=lastIndex){
            lds.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        lds.push_back(nums[lastIndex]);
        reverse(lds.begin(),lds.end());
        return lds;
    }
};