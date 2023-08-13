//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{
public:
    long long evenFibSum(int N){
        // code here
        long long sum =0;
        int dp[N+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=N;i++)
        {
            dp[i] = (dp[i-1]+ dp[i-2])%mod;
            if(dp[i]>N)break;
            if(dp[i]%2==0)sum = (sum+ dp[i]);
        }
       return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenFibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends