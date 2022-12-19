class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
        int ans=INT_MIN,prod=1;
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            ans=max(ans,prod);
            if(prod==0){prod=1;}
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            ans=max(ans,prod);
            if(prod==0){prod=1;}
        }
        
        return ans; 
        
        
//         int product =1;
//         int maxi =INT_MIN;
//         for(int i=0;i<nums.size();i++){
//            product=(nums[i]*product);
//            maxi = max(maxi,product);
//            if(product==0)
//            product=1;

//         }
//         product = 1;
       
//        for (int i = nums.size()-1; i>=0; i--) {
//            product = product * nums[i];
//            maxi = max(product, maxi);
//            if(product == 0) {
//               product = 1;
//            }      
//        }
      
//         return maxi;
    }
};