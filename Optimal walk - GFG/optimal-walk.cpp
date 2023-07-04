//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long dp[100001];
    long long solve(long long n,long long a,long long b){

        if(n<=0)

            return INT_MAX;

        if(n==1)

            return a;

        if(dp[n]!=-1)

            return dp[n];

        return dp[n]=min(a+solve(n-1,a,b),(n%2)*a+b+solve((n+1)/2,a,b));

    }

    long long optimalWalk(long long N, long long A, long long B){

        // code here

        memset(dp,-1,sizeof(dp));

        return solve(N,A,B);

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N, A, B;
        cin>>N>>A>>B;
        
        Solution ob;
        cout<<ob.optimalWalk(N, A, B)<<"\n";
    }
    return 0;
}
// } Driver Code Ends