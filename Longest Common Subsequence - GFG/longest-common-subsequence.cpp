//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int lc(string s1, int ind1, string s2, int ind2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2]; 
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+ lc(s1,ind1-1,s2,ind2-1,dp);
        else return dp[ind1][ind2]=max(lc(s1,ind1-1,s2,ind2,dp), lc(s1,ind1,s2,ind2-1,dp));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<int>prev(m+1,0);vector<int>curr(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) curr[ind2]=1+ prev[ind2-1];
                else curr[ind2]=max(prev[ind2], curr[ind2-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends