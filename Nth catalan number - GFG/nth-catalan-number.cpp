//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<long long int> v(n+1);
        int mod=1000000007;
        v[0]=1;
        v[1]=1;
        
        for(int i=2 ; i<=n; i++){
            v[i]=0;
            for(int j=0; j<i; j++){
                v[i]=(v[i]+v[j]*v[i-j-1])%mod;
            }
        }
        return v[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends