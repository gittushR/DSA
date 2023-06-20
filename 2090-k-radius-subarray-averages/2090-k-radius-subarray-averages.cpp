class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        
        long long windowSum = 0;
        vector<int> ans(n, -1);

        if (n < windowSize) {
            return ans;
        }
        int i=0,j=0;
        while(j<n){
            windowSum+=nums[j];
            if(j-i+1==windowSize){
                //cout<<j<<windowSum<<endl;
                ans[j-k]=windowSum/windowSize;
                windowSum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};