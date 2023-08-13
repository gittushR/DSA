//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{
public:
    long long evenFibSum(int N){
        // code here
        long long sum =0;
        int prev1=1,prev2=1,curr;
        for(int i=2; i<=N;i++)
        {
            curr = (prev2+ prev1)%mod;
            if(curr>N)break;
            if(curr%2==0)sum = (sum+ curr);
            prev1=prev2;
            prev2=curr;
        }
       return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenFibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends