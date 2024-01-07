class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int> &nums)
        {
            int ans = 0;
            int n = nums.size();

            vector<unordered_map<int, int>> dp(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    long long int diff =(long long int) nums[j] - nums[i];
                    if (diff > INT_MAX or diff < INT_MIN) continue;
                    int n2 = dp[i][(int) diff];
                    int n1 = dp[j][(int) diff];
                    ans += n1;
                    dp[i][diff] = n1 + n2 + 1;
                }
            }
            return ans;
        }
};