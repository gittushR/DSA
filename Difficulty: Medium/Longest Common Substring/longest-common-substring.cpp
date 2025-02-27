//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size(), m=s2.size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)memo[i][0]=0;
        for(int i=0;i<m;i++)memo[0][i]=0;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])memo[ind1][ind2]=1+memo[ind1-1][ind2-1];
                else memo[ind1][ind2]=0;
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans = max (ans,memo[i][j]);
            }
        }
        return ans;        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends