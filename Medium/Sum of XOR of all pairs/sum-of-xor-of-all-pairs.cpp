//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector<int> zero(32,0);
    	vector<int> ones(32,0);
    	for(int i=0;i<n;i++){
    	    int j=0;
    	    while(arr[i] || j<32){
    	        if(arr[i]&1)ones[j]++;
    	        else zero[j]++;
    	        if(arr[i]!=0)arr[i]=arr[i]>>1;
    	        j++;
    	    }
    	}
    	long long int ans=0;
    	for(int i=0;i<32;i++){
    	    ans+=(pow(2,i))*ones[i]*zero[i];
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends