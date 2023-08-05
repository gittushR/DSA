class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0], mn=nums[0];
        int ans=mx;
        for(int i=1; i<nums.size(); i++){
            ans = max(ans, mx);
            if(nums[i]<0) swap(mx, mn);
            mx = max(nums[i], mx*nums[i]);
            mn = min(nums[i], mn*nums[i]);
        }
        return max(ans, mx);
    }
};