class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back(nums1[i]);
            for(int i=0;i<nums2.size();i++)
            ans.push_back(nums2[i]);
            sort(ans.begin(),ans.end());
            float median=0;
            int n=ans.size();
    if(n%2 == 0)
        median = (ans[(n-1)/2] + ans[n/2])/2.0;
    else
        median = ans[n/2];
    
    return median;
    }
};