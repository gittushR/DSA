class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<=1)return;
        
        if(k%nums.size()==0)return;
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};