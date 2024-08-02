//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int maxLength=0;
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxLength=max(maxLength,i+1);
            }
            int rem = sum-k;
            if(mp.find(rem)!=mp.end()){
                int l = i-mp[rem];
                maxLength = max(maxLength,l);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
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