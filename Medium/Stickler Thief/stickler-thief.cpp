//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1) return arr[0];
        if(n==2) return max(arr[0], arr[1]);
        vector<int> dp(n);
        dp[0]=arr[0];
        dp[1]=arr[1];
        dp[2]=dp[0]+arr[2];
        for(int i=3; i<n; i++){
            dp[i] = arr[i]+max(dp[i-2], dp[i-3]);
        }
        return max(dp[n-2], dp[n-1]);
        // return helper(ind);
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