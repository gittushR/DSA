class Solution
{
    public:
        int longestSubarray(vector<int> &nums)
        {
            if (nums.size() == 0) return 0;
            vector<int> sums;
            int sum = 0;
            int arrsum=0;
            for (int i = 0; i < nums.size(); i++)
            {
                arrsum+=nums[i];
                if (nums[i] == 0)
                {
                    if (sum != 0) sums.push_back(sum);
                    sums.push_back(0);
                    sum = 0;
                }
                else
                {
                    sum += nums[i];
                }
            }
            if(arrsum==0)return 0;
            sums.push_back(sum);
            int ans = INT_MIN;
            if (sums.size() == 1) return sums[0] - 1;
            else if (sums.size() == 2)
            {
                sort(sums.begin(), sums.end());
                return sums[1];
            }
            else
            {
                for (int i = 0; i < sums.size() - 2; i++)
                {
                    int s = sums[i] + sums[i + 2];
                    ans = max(ans, s);
                }
            }
            return ans;
        }
};