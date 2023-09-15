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
        vector<vector<int>> memo(n,vector<int>((sum/2)+1,0));
        for(int i=0;i<n;i++)memo[i][0]=1;
        if(sum/2>=arr[0])memo[0][arr[0]]=1;
        for(int ind=1;ind<=n-1;ind++){
            for(int target=1;target<=sum/2;target++){
                int notTake=memo[ind-1][target];
                int take=0;
                if(target>arr[ind])take=memo[ind-1][target-arr[ind]];
                memo[ind][target]=take || notTake;
            }
        }
        return memo[n-1][sum/2];
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