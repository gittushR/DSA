//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int sum=0;
        int maxLen=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int len=0;
            sum+=arr[i];
            if(sum==k){
                len=i+1;
                maxLen=max(len,maxLen);
            }
            int remSum=sum-k;
            if(mp.find(remSum)!=mp.end()){
                len=i-mp[remSum];
                maxLen=max(maxLen,len);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return maxLen;
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