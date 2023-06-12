//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int ans;
        vector<int> maxprice(n);
        maxprice[0] = price[0];
        for(int i=1; i<n; ++i){
            int maxi= INT_MIN;
            for(int cut=1; cut<=i; ++cut){
                maxprice[i] = max(price[i], maxprice[cut-1]+maxprice[i-cut]);
                maxi = max(maxi, maxprice[i]);
            }
            maxprice[i] = maxi;
        }
        ans = maxprice[n-1];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends