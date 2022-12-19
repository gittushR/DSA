class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left_sum(n);
        vector<int> right_sum(n);
        vector<int> ans(n);

        left_sum[0]=1;
        right_sum[n-1]=1;
        
        for(int i=1;i<n;i++){
            left_sum[i]=nums[i-1]*left_sum[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            right_sum[i]=nums[i+1]*right_sum[i+1];
        }
        
        for(int i=0;i<n;i++){
            ans[i]=left_sum[i]*right_sum[i];
        }
        return ans;
    }
};