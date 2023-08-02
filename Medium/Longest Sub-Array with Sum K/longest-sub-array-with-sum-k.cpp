//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<long long, int> prevSum;
        long long sum=0;int maxLen=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k){
                maxLen=max(maxLen,i+1);
            }
            long long rem=sum-k;
            if(prevSum.find(rem)!=prevSum.end()){
                int len=i-prevSum[rem];
                maxLen=max(maxLen, len);
            }
            if(prevSum.find(sum)==prevSum.end()){
                prevSum[sum]=i;
            }
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