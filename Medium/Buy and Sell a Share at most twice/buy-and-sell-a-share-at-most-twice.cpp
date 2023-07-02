//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
    //Write your code here..
    int n = prices.size();
        int dp[n+1][2][3];
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
              for(int k=0;k<3;k++){
                  dp[i][j][k]=0;
              }  
            }
        }
        for (int i = 0; i < 3; i++)
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
                for (int cap = 1; cap < 3; cap++)
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
        return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends