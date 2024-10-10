class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int ind1=n1-1,ind2=n2-1;
        int ans=0;
        while(ind1>=0 and ind2>=0){
            if(nums2[ind2]>=nums1[ind1]){
                ans=max(ans,ind2-ind1);
                ind1--;
            }else{
                while(ind2>=0 and nums2[ind2]<nums1[ind1]){
                    ind2--;
                }
            }
        }
        return ans;
    }
};