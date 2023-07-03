//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fn(int total, int lengths[], int prices[],int index,vector<vector<int>> &dp){
        if(index==0){
            if(total>=lengths[0])return total*prices[0];
            else return 0;
        }
        if(dp[index][total]!=-1)return dp[index][total];
        int notCut=fn(total,lengths,prices,index-1,dp);
        int cut=-1e9;
        if(total>=lengths[index]){
            cut=prices[index]+fn(total-lengths[index],lengths,prices,index,dp);
        }
        return dp[index][total]=max(notCut, cut);
    }
    int cutRod(int prices[], int n) {
        //code here
        int lengths[n];
        for(int i=1;i<=n;i++){
            lengths[i-1]=i;
        }
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(n,lengths,prices,n-1,dp);
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