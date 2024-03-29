class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        sort(nums.begin() , nums.end());
        for(int i=0; i<n/2; i++)
        {
            int pair = nums[i] + nums[n-1-i];
            ans = max(ans, pair);
        }
        return ans;
        
    }
};