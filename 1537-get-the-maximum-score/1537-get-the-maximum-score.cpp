class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        long long sum1=0,sum2=0;
        long long ans=0;
        while(i<n and j<m){
            if(nums1[i]<nums2[j]){
                sum1+=nums1[i];
                i++;
            }else if(nums1[i]> nums2[j]){
                sum2+=nums2[j];
                j++;
            }else{
                ans+=nums1[i]+max(sum1,sum2);
                sum1=0;
                sum2=0;
                i++;j++;
            }
        }
        while(i<n){
            sum1+=nums1[i];i++;
        }
        while(j<m){
            sum2+=nums2[j];j++;
        }
        ans+=max(sum1,sum2);
        return ans % 1000000007;
    }
};