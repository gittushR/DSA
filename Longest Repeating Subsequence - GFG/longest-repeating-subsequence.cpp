//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int longestCommonSub(string s1,int ind1, string s2,int ind2,vector<vector<int>> &dp){
	        if(ind1==-1 or ind2==-1)return 0;
	        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
	        int ans=0;
	        if(s1[ind1]==s2[ind2] and ind1!=ind2)ans=1+longestCommonSub(s1,ind1-1,s2,ind2-1,dp);
	        else ans=max(longestCommonSub(s1,ind1-1,s2,ind2,dp),longestCommonSub(s1,ind1,s2,ind2-1,dp));
	        return dp[ind1][ind2]=ans;
	    }
		int LongestRepeatingSubsequence(string s1){
		    // Code here
		    int n=s1.size();
		    string s2=s1;
		    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		    for(int ind1=1;ind1<=n;ind1++){
		        for(int ind2=1;ind2<=n;ind2++){
		            int ans=0;
        	        if(s1[ind1-1]==s2[ind2-1] and (ind1-1)!=(ind2-1))ans=1+dp[ind1-1][ind2-1];
        	        else ans=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        	        dp[ind1][ind2]=ans;
		        }
		    }
		    return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends