class Solution
{
    public:
        int fn(int divisor, vector<int> arr)
        {
            int count = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                count += ceil((double) arr[i] / divisor);
            }
            return count;
        }
    int smallestDivisor(vector<int> &nums, int k)
    {
        int maxi = -1e8;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }
        int low = 1, high = maxi;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int totalDivisions = fn(mid, nums);
            if (totalDivisions <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};