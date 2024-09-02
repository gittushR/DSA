//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        int curr=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum==K){
                curr=i+1;
                ans=max(ans,curr);
            }
            int rem=sum-K;
            if(mp.find(rem)!=mp.end()){
                curr=i-mp[rem];
                ans=max(ans,curr);
            }
            if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return ans;
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