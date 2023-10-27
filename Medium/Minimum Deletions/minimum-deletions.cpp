//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // int helper(string s1, string s2, int ind1, int ind2,vector<vector<int>> &dp){
    //     if(ind1<0 || ind2<0)return 0;
    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //     if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+helper(s1,s2,ind1-1,ind2-1,dp);
    //     else return dp[ind1][ind2]=max(helper(s1,s2,ind1-1,ind2,dp), helper(s1,s2,ind1,ind2-1,dp));
    // }
    int minimumNumberOfDeletions(string s1) { 
        // code here
        int n=s1.size();
        string s2=s1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        reverse(s2.begin(),s2.end());
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        int length=0;
        for(int ind1=1;ind1<n+1;ind1++){
            for(int ind2=1;ind2<n+1;ind2++){
                    if(s1[ind1-1]==s2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                    else dp[ind1][ind2]=max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        length=dp[n][n];
        return n-length;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends