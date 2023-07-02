//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int n, int prices[]) {
        // code here
        int dp[n+1][2][K+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
              for(int k=0;k<K+1;k++){
                  dp[i][j][k]=0;
              }  
            }
        }
        for (int i = 0; i < K+1; i++)
        {
            dp[n][0][i] = dp[n][1][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j][0] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < K+1; cap++)
                {
                    int profit=0;
                    if (buy)
                    {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind+1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + dp[ind + 1] [1] [cap - 1], dp[ind + 1] [0] [cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends