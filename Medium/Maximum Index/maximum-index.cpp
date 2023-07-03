//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int nums[n];
        for(int i =0;i<n;i++){
            nums[i]=arr[i];
        }
        sort(nums,nums+n);
        int k =n-1;
        int maxi=0;
        int s=0;
        int e=n-1;
        while(s<e){
            int x = e-s;
            if(arr[s]<=arr[e]){
                maxi = max(x,maxi);
                s++;
                e = n-1;
            }
            else if(arr[s]==nums[k]){
                k--;
                s++;
            }
            else{
                e--;
            }
        }
        
        return maxi;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends