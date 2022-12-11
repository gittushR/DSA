class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1)return;
        if(k%nums.size()==0)return;
        int n=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+n);
        reverse(nums.begin()+n,nums.end());
    }
};