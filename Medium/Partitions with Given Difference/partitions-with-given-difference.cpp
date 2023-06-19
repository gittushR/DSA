//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public: 
    int mod = 1e9+7;
    int perfectSum(vector<int>& arr, int n, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        dp[0][0] = 1;
        for(int i=1; i<sum+1; i++) dp[0][i] = 0;
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
                else dp[i][j] = dp[i-1][j]%mod;
            }
        }    
        return dp[n][sum]%mod;
        
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(auto i:arr) sum += i;
        if((sum+d)%2) return 0;
        int s1 = (d + sum) / 2;
        return perfectSum(arr, n, s1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends