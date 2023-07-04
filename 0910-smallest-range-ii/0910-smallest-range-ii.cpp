class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0],maxi=nums[n-1];
        int ans=maxi-mini;
        for(int i=0;i<n-1;i++){
            // if(nums[i]-k<0)continue;
            mini=min(nums[0]+k,nums[i+1]-k);
            maxi=max(nums[n-1]-k,nums[i]+k);
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};