class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        int ans=1e9;
        while(s<=e){
            mid=(s+e)/2;
            // if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])return nums[mid];
            if(nums[s]<=nums[mid]){//left sorted
                ans=min(ans,nums[s]);
                s=mid+1;
            }else{//right sorted
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};