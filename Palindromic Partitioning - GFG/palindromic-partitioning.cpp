//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int palindromicPartition(string str)
    // {
    //     vector<int>ans;
    //     vector<string> path;
    //     check(0,str, path, ans);
    //     sort(ans.begin(),ans.end());
    //     return ans[0]-1;
    // }
    // void check(int index, string s, vector<string> &path, vector<int> &ans){
    //     if(index==s.size()){
    //         ans.push_back(path.size());
    //         return;
    //     }
        
    //     for(int i=index;i<s.size();i++){
    //         if(isPalin(s,index,i)){
    //             path.push_back(s.substr(index,i-index+1));
    //             check(i+1,s,path,ans);
    //             path.pop_back();
    //         }
    //     }
    // }
    // bool isPalin(string s, int start, int end){
    //     while(start<=end){
    //     if(s[start++]!=s[end--])return false;
    // }
    //     return true;
    // }
    bool isPalindrome(string str,int i,int j){
        str=str.substr(i,j-i+1);
        string rev=str;
        reverse(rev.begin(),rev.end());
        if(str==rev){
            return true;
        }else{
            return false;
        }
    }
    int helper(string &str,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==j){
            return 0;
        }
        if(isPalindrome(str,i,j)){
            return 0;
        }
        int ans=501;
        for(int k=i;k<=j-1;k++){
            int smallans1,smallans2;
            if(dp[i][k]!=-1){
                smallans1=dp[i][k];
            }else{
                smallans1=helper(str,i,k,dp);
            }
            if(dp[k+1][j]!=-1){//{ ##checking to reduce overhead of making a recursive call,
            //                     ##we wouldnt have needed it but ispalin. function is killing us with TLE
            smallans2=dp[k+1][j];
            }else{
                smallans2=helper(str,k+1,j,dp);
            }
            int temp=1+smallans1+smallans2;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;}
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(str,0,str.size()-1,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends