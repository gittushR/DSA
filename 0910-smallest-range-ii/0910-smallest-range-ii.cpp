class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int mini=min(nums[0]+k,nums[j]-k);
            int maxi=max(nums[n-1]-k,nums[i]+k);
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};