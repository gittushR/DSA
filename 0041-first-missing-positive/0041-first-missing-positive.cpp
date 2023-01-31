class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<1000000 && nums[i]>=0)
                mp[nums[i]]++;
        }
        for(int i=1;i<1000000;i++)
        {
            if(mp[i]==0)
                return i;
        }
        return -1;
    }
};