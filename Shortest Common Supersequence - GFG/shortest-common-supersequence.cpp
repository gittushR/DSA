//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int j=0;j<=n;j++)dp[0][j]=0;
        
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(X[ind1-1]==Y[ind2-1])dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        int i=m,j=n;
        string ans="";
        while(i>0 and j>0){
            if(X[i-1]==Y[j-1]){
                ans+=X[i-1];
                i--,j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans+=X[i-1];
                i--;
            }else{
                ans+=Y[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=X[i-1];
            i--;
        }
        while(j>0){
            ans+=Y[j-1];
            j--;
        }
        //cout<<ans<<endl;
        return m+n-dp[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends