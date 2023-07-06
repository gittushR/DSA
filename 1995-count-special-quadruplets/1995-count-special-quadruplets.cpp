class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int i, j, k, l, count=0;
        for(i=0 ; i<nums.size()-3 ; i++)
        {
            for(j=i+1 ; j<nums.size()-2 ; j++)
            {
                for(k=j+1 ; k<nums.size()-1 ; k++)
                {
                    for(l=k+1 ; l<nums.size() ; l++)
                    {
                        if(nums[i]+nums[j]+nums[k]==nums[l])
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};