//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> msis(n);
	    for(int ind=0;ind<n;ind++){
	        msis[ind]=arr[ind];
	        for(int prev_ind=0;prev_ind<ind;prev_ind++){
	            if(arr[prev_ind]<arr[ind] and msis[prev_ind]+arr[ind]>msis[ind]){
	                msis[ind]=msis[prev_ind]+arr[ind];
	            } 
	        }
	    }
	    int maxSum=0;
	    for(int i=0;i<msis.size();i++){
	        maxSum=max(maxSum,msis[i]);
	    }
	    return maxSum;
	}  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends