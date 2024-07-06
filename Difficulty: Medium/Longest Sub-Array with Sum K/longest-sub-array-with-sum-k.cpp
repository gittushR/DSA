//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        map<int,int> mpp;
        int maxLength=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxLength=max(maxLength,i+1);
            }
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end()){
                maxLength=max(maxLength,i-mpp[rem]);
            }
            
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends