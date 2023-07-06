class Solution
{
    public:
        bool increasingTriplet(vector<int> &arr)
        {
            int n=arr.size();
            vector<int> temp;
            temp.push_back(arr[0]);
            int len = 1;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > temp.back())
                {
                    temp.push_back(arr[i]);
                    len++;
                }
                else
                {
                    int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                    temp[ind] = arr[i];
                }
            }
            if(len>=3)return true;
            return false;
        }
};