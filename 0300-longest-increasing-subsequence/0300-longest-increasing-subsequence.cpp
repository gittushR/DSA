class Solution {
public:
    int lengthOfLIS(vector<int>& s) {
            int n = s.size();
    vector<int> temp;
    temp.push_back(s[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] > temp.back())
        {
            temp.push_back(s[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), s[i]) - temp.begin();
            temp[ind] = s[i];
        }
    }
    return len;
    }
};