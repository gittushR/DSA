class Solution
{
    public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n=nums.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = 0 + prev[prev_ind + 1];
                if (prev_ind == -1 or nums[ind] > nums[prev_ind])
                {
                    len = max(len, 1 + prev [ind+1]);
                }
                curr[prev_ind + 1] = len;
            }
            prev=curr;
        }
        return prev[0];
    }
};