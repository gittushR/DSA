//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int fn(int ind1, int ind2, string s1, string s2,vector<vector<int>>&dp){
        if(ind1<0 or ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+fn(ind1-1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]=max(fn(ind1-1,ind2,s1,s2,dp),fn(ind1,ind2-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x,vector<int>(y,-1));
        return fn(x-1,y-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends