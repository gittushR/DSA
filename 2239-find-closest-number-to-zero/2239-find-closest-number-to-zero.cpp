class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
    int ans = 0;
    int min_dist = INT_MAX;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        min_dist = min(min_dist, abs(nums[i]));
        if (min_dist == abs(nums[i]))
        {
            if(nums[i]<0 && ans!=min_dist)
                    ans = nums[i];
            else
                ans = min_dist;
        }
    }
    return ans;
    }
};