//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int nums[], int n, int k) {
        // code here
        sort(nums,nums+n);
        int mini=nums[0],maxi=nums[n-1];
        int ans=maxi-mini;
        for(int i=0;i<n-1;i++){
            // if(nums[i]-k<0)continue;
            mini=min(nums[0]+k,nums[i+1]-k);
            maxi=max(nums[n-1]-k,nums[i]+k);
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends