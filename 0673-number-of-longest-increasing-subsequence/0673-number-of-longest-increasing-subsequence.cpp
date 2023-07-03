class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        int lastIndex=0;
        for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(arr[prev_ind]<arr[ind] and 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                    cnt[ind]=cnt[prev_ind];
                }else if(arr[prev_ind]<arr[ind] and 1+dp[prev_ind]==dp[ind]){
                    cnt[ind]+=cnt[prev_ind];
                }
            }
            maxi=max(maxi,dp[ind]); 
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)nos+=cnt[i];
        }
        return nos;
    }
};