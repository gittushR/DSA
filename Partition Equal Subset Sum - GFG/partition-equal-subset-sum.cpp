//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool helper(int ind, int target, int arr[],vector<vector<int>>&memo){
        if(target==0)return 1;
        if(ind==0){
            if(arr[0]==target)return 1;
            return 0;
        }
        if(memo[ind][target]!=-1)return memo[ind][target];
        int notTake=helper(ind-1,target,arr,memo);
        int take=0;
        if(target>arr[ind])take=helper(ind-1,target-arr[ind],arr,memo);
        return memo[ind][target]=take || notTake;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        if(sum % 2!=0)return false;
        vector<vector<int>> memo(n,vector<int>((sum/2)+1,-1));
        return helper(n-1,sum/2,arr,memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends