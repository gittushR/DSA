//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int helper(int ind, int arr[],vector<int>&dp){
        if(ind==0)return arr[0];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int take=arr[ind]+helper(ind-2,arr,dp);
        int notTake=helper(ind-1,arr,dp);
        return dp[ind]=max(take,notTake);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n,-1);
        return helper(n-1,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends