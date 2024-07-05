class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        if(nums.size()==1)return 1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                swap(nums[j],nums[i+1]);
                i++;j++;
            }
        }
        return i+1;
    }
};