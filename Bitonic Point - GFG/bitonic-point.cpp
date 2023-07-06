//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int nums[], int n) {
	    // code here
	    int low=1,high=n-2,mid;
        if(n==1)return 0;
        if(nums[0]>=nums[1])return nums[0];
        if(nums[n-1]>=nums[n-2])return nums[n-1];
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>=nums[mid-1] and nums[mid]>=nums[mid+1])return nums[mid];
            if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }else if(nums[mid]>nums[mid+1]){
                high=mid-1;
            }else low=mid+1;
        }
        return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends